#include <bits/stdc++.h>
#include "bit_set.h"

using namespace std;

BitSet::BitSet() {}

BitSet::BitSet(int _size) { setSize(_size); }

/**
 * @brief Set the Size of bitset
 *
 * @param _size Bitset size
 */
void BitSet::setSize(int _size) {
    size = _size;
    __constructBucket(size);
}

/**
 * @brief Set bit at given index
 *
 * @param idx Index to enable bit
 */
void BitSet::set(int idx) {
    if (idx >= size) {
        throw invalid_argument("Index exceeds the given size");
    }
    int bucketIdx = floor((double)idx / BIT_WIDTH);
    int bitToSet = idx % (int)BIT_WIDTH;
    uint64_t& bucketToSet = buckets[bucketIdx];
    bucketToSet |= (1 << bitToSet);
}

/**
 * @brief Check if bit is flipped at given index
 *
 * @param idx
 * @return true | false
 */
bool BitSet::test(int idx) {
    if (idx >= size) {
        throw invalid_argument("Index exceeds the given size");
    }
    int bucketIdx = floor((double)idx / BIT_WIDTH);
    int bitToCheck = idx % (int)BIT_WIDTH;
    uint64_t& bucketToCheck = buckets[bucketIdx];
    return bucketToCheck & (1 << bitToCheck);
}

void BitSet::__constructBucket(int size) {
    int bucketsAllocated = ceil((double)size / BIT_WIDTH);  //
    buckets.assign(bucketsAllocated, 0);
}