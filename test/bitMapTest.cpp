#include "include/BitMapFree.hpp"

int main() {

    BitMapFree m(0, 100);
    m.used(0, 1);
    m.used(1, 1);
    m.used(2, 1);
    m.used(3, 1);

    return 0;
}