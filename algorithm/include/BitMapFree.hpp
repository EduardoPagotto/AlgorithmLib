#ifndef __BITMAPFREE__HPP__
#define __BITMAPFREE__HPP__

#include <list>
#include <stdint.h>
#include <vector>

struct BitMapDataSet {
    uint32_t begin;
    uint32_t end;
};

struct BlockDataSet {
    uint32_t startBlock;
    uint32_t size;
};

class BitMapFree {
  public:
    BitMapFree(const uint32_t& begin, const uint32_t& length);
    ~BitMapFree();
    void markAsUsed(const uint32_t& begin, const uint32_t& length);

    uint32_t markAsUnUsed(const uint32_t& begin, const uint32_t& length);

    inline uint32_t getMaxOffset() const { return maxOffSet; }
    uint32_t usedLength();
    uint32_t unUsedLength();
    std::vector<BlockDataSet> usedRegions(const uint32_t& minLength = 1);
    std::vector<BlockDataSet> unUsedRegions(const uint32_t& minLength = 1);

  private:
    std::list<BitMapDataSet> dataSet;
    BitMapDataSet limites;
    uint32_t maxOffSet;
};

#endif