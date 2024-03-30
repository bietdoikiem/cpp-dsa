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
        tree.assign(size, 0);
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

int reversePairs(vector<int>& nums) {
    int n = (int) nums.size();
    // Compress values
    vector<int> allV = nums;
    sort(allV.begin(), allV.end());
    allV.resize(unique(allV.begin(), allV.end()) - allV.begin());
    int m = allV.size();
    for (int i = 0; i < n; i++) {
        int vIdx = lower_bound(allV.begin(), allV.end(), nums[i]) - allV.begin();
        nums[i] = vIdx;
    }
    
    int cnt = 0;
    FenwickTree<long long> t(m+1);
    for (int i = n-1; i >= 0; i--) {
        int halfIdx = lower_bound(allV.begin(), allV.end(), ceil((double) allV[nums[i]] / 2.0)) - allV.begin();
        int q = t.query(halfIdx);
        cnt += q;
        t.update(nums[i] + 1, 1);
    }
    return cnt;
}

int main() {
    // Test 1
    vector<int> nums = {1,3,2,3,1};
    int ans = reversePairs(nums);
    cout << ans << endl; // 2

    // Test 2
    nums = {2,4,3,5,1};
    ans = reversePairs(nums);
    cout << ans << endl; // 3
    return 0;
}