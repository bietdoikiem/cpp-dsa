#include <bits/stdc++.h>

using namespace std;

/**
 * NOTE: Fenwick Tree is 1-based index data structure.
 * Please make your data is 1-based index already with the sufficient size when initializing the tree.
 */
template<typename T>
class FenwickTree {
public:
    int size;
    vector<T> tree;

    FenwickTree(int _size) {
        size = _size;
        tree = vector<T>(size, 0);
    }

    int query(int idx) {
        T res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & (-idx);
        }
        return res;
    }

    void update(int idx, T delta) {
        while (idx < size) {
            tree[idx] += delta;
            idx += idx & (-idx);
        }
    }
};

int main() {
    return 0;
}