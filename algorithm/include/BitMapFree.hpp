#ifndef __BITMAPFREE__HPP__
#define __BITMAPFREE__HPP__

#include <stdint.h>
#include <vector>

struct BitMapDataSet {
    uint32_t begin;
    uint32_t end;
};

class BitMapFree {
  public:
    BitMapFree();
    ~BitMapFree();

    void used(const uint32_t& pos, const uint32_t& size);

  private:
    // std::vector<BitMapDataSet> dataSet;
    std::vector<uint32_t> dataSet;
};

#endif