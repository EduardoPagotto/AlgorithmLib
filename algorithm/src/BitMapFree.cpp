#include "include/BitMapFree.hpp"

BitMapFree::BitMapFree(const uint32_t& begin, const uint32_t& length) {

    this->limites.begin = begin;
    this->limites.end = begin + length;
    maxOffSet = 0;
}

BitMapFree::~BitMapFree() {}

void BitMapFree::used(const uint32_t& begin, const uint32_t& length) {

    BitMapDataSet b;
    b.begin = begin;
    b.end = begin + length;

    for (auto it = dataSet.begin(); it != dataSet.end(); it++) {

        if (begin == it->end) {
            it->end = b.end;

            auto next = std::next(it);
            if (next != dataSet.end()) {
                if (it->end == next->begin) {
                    it->end = next->end;

                    dataSet.erase(next);
                }
            }

            if (it->end > this->maxOffSet)
                this->maxOffSet = it->end;

            return;
        }
    }

    if (b.end > this->maxOffSet)
        this->maxOffSet = b.end;

    this->dataSet.push_back(b);
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