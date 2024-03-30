#include <bits/stdc++.h>

using namespace std;

// Space & Time: O(N*LogN)
vector<vector<int>> preprocess(vector<int>& nums) {
    // Find the minimum of elements from a window of 1,2,4,8... (power of 2)
    int n = (int) nums.size();
    int lgn = __lg(n);
    vector<vector<int>> m(n, vector<int>(lgn+1, INT_MAX));
    for (int i = 0; i < n; i++) m[i][0] = nums[i];
    for (int j = 1; j <= lgn; j++) {
        // Sparse Length = 2^j
        // Formula: m[i][j] = min(m[i][j-1], m[i + (1 << (j-1))][j-1])
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            m[i][j] = min(m[i][j-1], m[i + (1 << (j-1))][j-1]);
        }
    }
    return m;
}

int query(vector<vector<int>>& m, int l, int r) {
    int n = r - l + 1;
    int j = __lg(n);
    return min(m[l][j], m[r - (1 << j) + 1][j]);
}

int main() {
    vector<int> nums = {2, 3, 4, 5, 3, 1, 1, 3};
    vector<vector<int>> m = preprocess(nums); // Preprocessed min sparse table
    int q1 = query(m, 1, 5);
    cout << "q1: " << q1 << endl;

    int q2 = query(m, 3, 4);
    cout << "q2: " << q2 << endl;

    int q3 = query(m, 3, 7);
    cout << "q3: " << q3 << endl;

    // TODEBUG
    // cout << "sparse table: " << endl;
    // for (int i = 0; i < m.size(); i++) {
    //     cout << i << ": [ ";
    //     for (auto& it: m[i]) {
    //         cout << it << ' ';
    //     }
    //     cout << ']' << endl;
    // }
    return 0;
}