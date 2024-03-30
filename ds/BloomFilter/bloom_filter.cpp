#include <bits/stdc++.h>

#include "bit_set.h"
#include "hasher.h"

using namespace std;

/**
 * @brief Bloom Filter designed to quickly check existing of integer key (i.e
 * entity integer ID)
 */
class BloomFilter {
public:
    BitSet bs;
    // Bloom Filter parameters calculator: https://hur.st/bloomfilter/
    int m;  // No. bits in bitset
    int k;  // No. hash functions

    BloomFilter(int _m, int _k) {
        m = _m;
        k = _k;
        bs.setSize(m);
    }

    /**
     * @brief Add an integer key to the filter.
     * - Time Complexity: O(k), k = no. hash functions 
     *
     * @param key Key
     */
    void add(int key) {
        uint64_t hashes[2] = {0};
        getHash(key, hashes);
        uint64_t h1 = hashes[0];
        uint64_t h2 = hashes[1];
        uint64_t h = h1;

        // Combinatorial Approach to generate different hash combinations
        // Source:
        // https://github.com/Claudenw/BloomFilters/wiki/Bloom-Filters----An-overview
        for (int i = 0; i < k; i++) {
            h += (k * h2);
            int bitIdx = h % m;
            bs.set(bitIdx);
        }
    }

    /**
     * @brief Check if key is present in the filter. Time Complexity: O(k), k =
     * no. hash functions
     *
     * @param key Key
     * @return true | false
     */
    bool isPresent(int key) {
        uint64_t hashes[2] = {0};
        getHash(key, hashes);
        uint64_t h1 = hashes[0];
        uint64_t h2 = hashes[1];
        uint64_t h = h1;

        // Combinatorial Approach to generate different hash combinations
        // Source:
        // https://github.com/Claudenw/BloomFilters/wiki/Bloom-Filters----An-overview
        for (int i = 0; i < k; i++) {
            h += (k * h2);
            int bitIdx = h % m;
            if (!bs.test(bitIdx)) {
                return false;
            }
        }
        return true;
    }

private:

    /**
     * @brief Get the 128-bit Hash (separated into 2 64-bit) of a key
     *
     * @param key Key to hash
     * @param out Result array (2 items/64-bit hashes)
     */
    void getHash(int key, void* out) {
        uint32_t seed = 4;
        int keyToHash = key;
        const int* keyPtr = &keyToHash;
        MurmurHash3_x64_128(keyPtr, sizeof(int), seed, out);
    }
};

/** Driver Program **/
int main() {
    BloomFilter bf(100000, 5);
    int key1 = 3;
    bf.add(key1);
    cout << "bf.isPresent result for key1: " << bf.isPresent(key1) << endl;

    int key2 = 13123;
    bf.add(key2);
    cout << "bf.isPresent result for key2: " << bf.isPresent(key2) << endl;
    return 0;
}