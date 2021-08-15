#include "include/BitMapFree.hpp"

bool compareSet(const BitMapDataSet& a, const BitMapDataSet& b) {
    if (a.begin < b.begin)
        return true;

    return false;
}

BitMapFree::BitMapFree(const uint32_t& begin, const uint32_t& length) {

    this->limites.begin = begin;
    this->limites.end = begin + length;
    maxOffSet = 0;
}

BitMapFree::~BitMapFree() {}

bool BitMapFree::markAsUsed(const uint32_t& begin, const uint32_t& length) {

    uint32_t end = begin + length;

    // fora de faixa
    if ((end > this->limites.end) || (begin < limites.begin))
        return false;

    bool alterado = false;

    for (auto it = dataSet.begin(); it != dataSet.end(); it++) {

        // node ja existe
        if ((begin >= it->begin) && (end <= it->end))
            return false;

        // adiciona length ao final de bloco ja existente
        if ((begin <= it->end) && (begin > it->begin)) {
            it->end = end;
            alterado = true;
        }

        // Adiciona length antes de bloco ja existente
        if (end == it->begin) {
            it->begin = begin;
            alterado = true;
        }

        // adiciona espaco entre 2 do blocos ja existente
        auto next = std::next(it);
        if (next != dataSet.end()) {
            if ((it->end >= next->begin) && (it->end < next->end)) {
                it->end = next->end;
                // remove residuo do ultimo bloco
                dataSet.erase(next);
            }
        }

        // verifica off-set de bloco alterado
        if (alterado) {
            if (end > maxOffSet)
                maxOffSet = end;

            return true;
        }
    }

    // verifica o offset de bloco novo
    if (end > maxOffSet)
        maxOffSet = end;

    // novo espaco longe dos espacos ja existentes
    BitMapDataSet b;
    b.begin = begin;
    b.end = end;
    this->dataSet.push_back(b);

    dataSet.sort(compareSet);
    return true;
}

uint32_t BitMapFree::markAsUnUsed(const uint32_t& begin, const uint32_t& length) {

    uint32_t ret = 0;
    uint32_t end = begin + length;

    for (auto it = this->dataSet.begin(); it != this->dataSet.end(); it++) {

        if (begin <= it->begin) {
            if (end >= it->end) {
                // remove o que estiver dentro do range
                it = dataSet.erase(it); // move foward
                it = std::prev(it);     // move backward

                ret++;
            } else if (end > it->begin) {
                // remove do inicio
                it->begin = end;
                ret++;
            }

        } else if (begin > it->begin) {

            if (end < it->end) {
                // remove um pedaço no meio do range
                uint32_t old_end = it->end;
                it->end = begin;

                this->dataSet.push_back(BitMapDataSet{end, old_end});

                ret++;

                dataSet.sort(compareSet);
                break;

            } else if (begin < it->end) {
                // remove do final
                it->end = begin;
                ret++;
            }
        }
    }

    return ret;
}

bool BitMapFree::isUsed(const uint32_t& begin, const uint32_t& length) {

    uint32_t end = begin + length;

    for (auto it = dataSet.begin(); it != dataSet.end(); it++) {
        if ((begin >= it->begin) && (end <= it->end)) {
            return true;
        }
    }

    return false;
}

bool BitMapFree::firstFree(uint32_t& begin, uint32_t& length) {

    uint32_t val = 0;

    if (this->dataSet.size() > 0) {
        auto it = this->dataSet.begin();
        val = it->begin - limites.begin;
        if (val >= 1) {
            begin = limites.begin;
            length = val;
            return true;
        }

        it++;
        for (; it != this->dataSet.end(); it++) {
            auto prev = std::prev(it);
            val = it->begin - prev->end;

            if (val >= 1) {
                begin = prev->end;
                length = val;
                return true;
            }
        }

        auto last = this->dataSet.back();
        val = limites.end - last.end;

        if (val >= 1) {
            begin = last.end;
            length = val;
            return true;
        }

    } else {
        val = limites.end - limites.begin;
        if (val >= 1) {
            begin = limites.begin;
            length = val;
            return true;
        }
    }

    return false;
}

uint32_t BitMapFree::findFirst(const uint32_t& minLength) {
    uint32_t ret = 0;
    uint32_t val = 0;

    if (this->dataSet.size() > 0) {

        auto it = this->dataSet.begin();
        val = it->begin - limites.begin;
        if (val >= minLength)
            return limites.begin;

        it++;
        for (; it != this->dataSet.end(); it++) {
            auto prev = std::prev(it);
            val = it->begin - prev->end;

            if (val >= minLength)
                return prev->end;
        }

        auto last = this->dataSet.back();
        val = limites.end - last.end;

        if (val >= minLength)
            return last.end;

    } else {
        val = limites.end - limites.begin;
        if (val >= minLength)
            return limites.begin;
    }

    return ret;
}

uint32_t BitMapFree::usedLength() {

    uint32_t ret = 0;

    for (auto block : this->dataSet)
        ret += block.end - block.begin;

    return ret;
}

uint32_t BitMapFree::unUsedLength() {

    uint32_t val = 0;
    if (this->dataSet.size() > 0) {

        auto it = this->dataSet.begin();
        val += it->begin - limites.begin;

        it++;
        for (; it != this->dataSet.end(); it++) {
            auto prev = std::prev(it);
            val += it->begin - prev->end;
        }

        auto last = this->dataSet.back();
        val += limites.end - last.end;

    } else {
        val += limites.end - limites.begin;
    }

    return val;
}

std::vector<BlockDataSet> BitMapFree::usedRegions(const uint32_t& minLength) {
    std::vector<BlockDataSet> ret;

    uint32_t val;
    for (auto block : this->dataSet) {

        val = block.end - block.begin;
        if (val >= minLength)
            ret.push_back(BlockDataSet{block.begin, val});
    }

    return ret;
}

std::vector<BlockDataSet> BitMapFree::unUsedRegions(const uint32_t& minLength) {
    std::vector<BlockDataSet> ret;

    uint32_t val;

    if (this->dataSet.size() > 0) {

        auto it = this->dataSet.begin();
        val = it->begin - limites.begin;
        if (val >= minLength)
            ret.push_back(BlockDataSet{limites.begin, val});

        it++;
        for (; it != this->dataSet.end(); it++) {
            auto prev = std::prev(it);
            val = it->begin - prev->end;

            if (val >= minLength)
                ret.push_back(BlockDataSet{prev->end, val});
        }

        auto last = this->dataSet.back();
        val = limites.end - last.end;

        if (val >= minLength)
            ret.push_back(BlockDataSet{last.end, val});

    } else {
        val = limites.end - limites.begin;
        if (val >= minLength)
            ret.push_back(BlockDataSet{limites.begin, val});
    }

    return ret;
}

void BitMapFree::load(uint32_t pointers[], const uint32_t& size) {
    for (uint32_t begin = 0; begin < size; begin += 2) {
        uint32_t end = begin + 1;
        if (pointers[end] > 0)
            this->dataSet.push_back(BitMapDataSet{pointers[begin], pointers[end]});
    }
}

uint32_t BitMapFree::save(uint32_t pointers[]) {

    uint32_t pos = 0;
    for (auto val : this->dataSet) {
        pointers[pos++] = val.begin;
        pointers[pos++] = val.end;
    }

    return pos--;
}

// bool binarySearch(std::vector<uint32_t>& array, const uint32_t& search, uint32_t& pos) {

//     uint32_t first = 0;
//     uint32_t last = array.size() - 1;
//     pos = (first + last) / 2;

//     while (first <= last) {

//         if (array[pos] < search) {
//             first = pos + 1;

//         } else if (array[pos] == search) {
//             pos += 1;
//             return true;
//         } else {
//             last = pos - 1;
//             pos = (first + last) / 2;
//         }

//         if (first > last)
//             return false;
//     }
// }