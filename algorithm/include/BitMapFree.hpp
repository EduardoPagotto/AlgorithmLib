#ifndef __BITMAPFREE__HPP__
#define __BITMAPFREE__HPP__

#include <list>
#include <stdint.h>

struct BitMapDataSet {
    uint32_t begin;
    uint32_t end;
};

class BitMapFree {
  public:
    BitMapFree(const uint32_t& begin, const uint32_t& length);
    ~BitMapFree();
    void used(const uint32_t& begin, const uint32_t& length);

  private:
    std::list<BitMapDataSet> dataSet;
    BitMapDataSet limites;
    uint32_t maxOffSet;
};

#endif