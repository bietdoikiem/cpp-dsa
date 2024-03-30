#ifndef BIT_SET_H
#define BIT_SET_H

#include <vector>
#include <stdint.h>
#include <math.h>

using namespace std;

class BitSet {
public:
    int size;

    BitSet();

    BitSet(int _size);

    /**
     * @brief Set the Size of bitset
     *
     * @param _size Bitset size
     */
    void setSize(int _size);

    /**
     * @brief Set bit at given index
     *
     * @param idx Index to enable bit
     */
    void set(int idx);

    /**
     * @brief Test if bit is flipped at given index
     *
     * @param idx
     * @return true | false
     */
    bool test(int idx);

private:
    vector<uint64_t> buckets;
    const double BIT_WIDTH = 64.0;

    /**
     * @brief Construct buckets of 64-bit unsigned integer
     *
     * @param size Size of bitset
     */
    void __constructBucket(int size);
};

#endif