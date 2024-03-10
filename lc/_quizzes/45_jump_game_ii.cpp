#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

// Time Complexity: O(N^2) => Max 10^8 = 1s in avg CPU processing time (Satisfied)
// Space Complexity: O(N)
int jump(vector<int>& nums) {
    int n = (int) nums.size();
    vector<int> dp(n);
    dp[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        dp[i] = INF;
        for (int j = 1; j <= nums[i] && i+j < n; j++) {
            dp[i] = min(dp[i], 1 + dp[i+j]);
        }
    }
    return dp[0];
}

int main() {
    // Test 1
    vector<int> in1 = {2,3,1,1,4};
    int out1 = jump(in1);
    cout << "out1: " << out1 << endl; // 2
    /**
     * The minimum number of jumps to reach the last index is 2.
     * Jump 1 step from index 0 to 1, then 3 steps to the last index.
     */

    // Test 2
    vector<int> in2 = {2,3,0,1,4};
    int out2 = jump(in2);
    cout << "out2: " << out2 << endl; // 2
    return 0;
}