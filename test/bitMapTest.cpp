#include "include/BitMapFree.hpp"

int main() {

    BitMapFree m(0, 100);
    uint32_t tot = m.unUsedLength();

    uint32_t begin = m.findFirst(1);
    m.markAsUsed(begin, 50);
    m.markAsUnUsed(10, 20);

    uint32_t pos, size;
    m.firstFree(pos, size);

    // m.markAsUsed(20, 5);

    // m.markAsUsed(30, 5);

    // m.markAsUsed(40, 5);

    // m.markAsUsed(90, 5);

    // m.markAsUnUsed(0, 100);

    auto lista = m.usedRegions();
    lista = m.unUsedRegions();
    return 0;
}