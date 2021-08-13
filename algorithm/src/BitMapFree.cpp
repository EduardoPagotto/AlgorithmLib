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

void BitMapFree::used(const uint32_t& begin, const uint32_t& length) {

    uint32_t end = begin + length;

    bool alterado = false;

    for (auto it = dataSet.begin(); it != dataSet.end(); it++) {

        if ((begin <= it->end) && (begin > it->begin)) {
            it->end = end;
            alterado = true;
        }

        auto prev = std::next(it);
        if (prev != it) {
            if (end == prev->begin) {
                prev->begin = begin;
                alterado = true;
            }
        }

        auto next = std::next(it);
        if (next != dataSet.end()) {

            if ((it->end >= next->begin) && (it->end < next->end)) {
                it->end = next->end;
                dataSet.erase(next);
            }
        }

        if (alterado) {
            dataSet.sort(compareSet);
            return;
        }
    }

    BitMapDataSet b;
    b.begin = begin;
    b.end = end;
    this->dataSet.push_back(b);

    dataSet.sort(compareSet);
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