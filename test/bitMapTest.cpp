#include "include/BitMapFree.hpp"

int main() {

    BitMapFree m(0, 10);
    m.used(0, 1);
    m.used(1, 2);
    m.used(5, 2);
    m.used(3, 2);

    return 0;
}