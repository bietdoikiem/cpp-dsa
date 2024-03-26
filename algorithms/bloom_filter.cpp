#include <bits/stdc++.h>

using namespace std;

class BitSet {
public:
    int size;

    BitSet() { }

    BitSet(int _size) {
        setSize(_size);
    }

    /**
     * @brief Set the Size of bitset
     * 
     * @param _size Bitset size
     */
    void setSize(int _size) {
        size = _size;
        __constructBucket(size);
    }

    /**
     * @brief Set bit at given index 
     * 
     * @param idx 
     */
    void set(int idx) {
        if (idx >= size) {
            throw invalid_argument("Index exceeds the given size");
        }
        int bucketIdx = floor((double) idx / BIT_WIDTH);
        int bitToSet = idx % (int) BIT_WIDTH;
        uint64_t& bucketToSet = buckets[bucketIdx];
        bucketToSet |= (1 << bitToSet);
    }

    /**
     * @brief Check if bit is flipped at given index
     * 
     * @param idx 
     * @return true | false
     */
    bool check(int idx) {
        if (idx >= size) {
            throw invalid_argument("Index exceeds the given size");
        }
        int bucketIdx = floor((double) idx / BIT_WIDTH);
        int bitToCheck = idx % (int) BIT_WIDTH;
        uint64_t& bucketToCheck = buckets[bucketIdx];
        if (bucketToCheck & (1 << bitToCheck)) {
            return true;
        }
        return false;
    }

private:    
    vector<uint64_t> buckets;
    const double BIT_WIDTH = 64.0;

    /**
     * @brief Construct buckets of 64-bit unsigned integer
     * 
     * @param size Size of bitset
     */
    void __constructBucket(int size) {
        int bucketsAllocated = ceil((double) size / BIT_WIDTH); // 
        buckets.assign(bucketsAllocated, 0);
    }
};

class BloomFilter {
public:
    BitSet bs;
    
    BloomFilter(int m) {
        bs.setSize(m);
    }
};

int main() {
    BitSet bs(1000);
    bs.set(737);
    cout << "check result: " << bs.check(737) << endl;
    return 0;
}