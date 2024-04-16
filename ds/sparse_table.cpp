#include <bits/stdc++.h>

template<typename T>
class SparseTable {
public:
    vector<vector<int>> m;

    SparseTable(vector<int&> nums) {
        __preprocess(nums);
    }

    // Space & Time: O(N*LogN)
    void __preprocess(vector<int>& nums) {
        // Find the minimum of elements from a window of 1,2,4,8... (power of 2)
        int n = (int) nums.size();
        int lgn = __lg(n);
        m.assign(n, vector<int>(lgn+1, INT_MAX));
        for (int i = 0; i < n; i++) m[i][0] = nums[i];
        for (int j = 1; j <= lgn; j++) {
            // Sparse Length = 2^j
            // Formula: m[i][j] = min(m[i][j-1], m[i + (1 << (j-1))][j-1])
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                m[i][j] = min(m[i][j-1], m[i + (1 << (j-1))][j-1]);
            }
        }
    }

    int query(int l, int r) {
        int n = r - l + 1;
        int j = __lg(n);
        return min(m[l][j], m[r - (1 << j) + 1][j]);
    }
};

int main() {
    return 0;
}