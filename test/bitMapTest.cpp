#include "include/BitMapFree.hpp"

int main() {

    BitMapFree m(0, 100);
    m.used(0, 1);
    m.used(1, 1);

    m.used(5, 1);
    m.used(4, 1);

    m.used(8, 1);
    m.used(10, 1);
    m.used(9, 1);

    m.used(12, 1);
    m.used(13, 1);

    m.used(15, 1);

    return 0;
}