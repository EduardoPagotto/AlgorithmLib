#include "include/BitMapFree.hpp"

int main() {

    BitMapFree m(0, 100);

    uint32_t tot = m.unUsedLength();

    m.markAsUsed(0, 5);

    m.markAsUsed(10, 5);

    m.markAsUsed(20, 5);

    m.markAsUnUsed(10, 1);

    auto lista = m.usedRegions();

    return 0;
}