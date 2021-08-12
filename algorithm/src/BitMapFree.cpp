#include "include/BitMapFree.hpp"

BitMapFree::BitMapFree() {}

BitMapFree::~BitMapFree() {}

void BitMapFree::used(const uint32_t& pos, const uint32_t& size) {

    uint32_t begin = pos;
    uint32_t end = pos + size;

    // BitMapDataSet b;
    // b.begin = end;
    // b.end = end;

    // bool newBegin = false;
    // bool newEnd = false;

    // for (auto it = this->dataSet.begin(); this->dataSet.end(); it++) {

    //     if (b.begin == it->begin) {}
    // }
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