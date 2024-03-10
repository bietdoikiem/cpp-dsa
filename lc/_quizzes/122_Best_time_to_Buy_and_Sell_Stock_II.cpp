#include <bits/stdc++.h>

using namespace std;

int fn(vector<vector<int>>& dp, vector<int>& prices, int idx, int state) {
    if (idx == (int) prices.size()) {
        return 0;
    }
    if (dp[idx][state] != -1) {
        return dp[idx][state];
    }
    if (state == 0) {
        // Skip
        dp[idx][state] = max(dp[idx][state], fn(dp, prices, idx+1, state));
        // Buy
        dp[idx][state] = max(dp[idx][state], fn(dp, prices, idx+1, 1) - prices[idx]);
    } else {
        // Skip
        dp[idx][state] = max(dp[idx][state], fn(dp, prices, idx+1, state));
        // Sell
        dp[idx][state] = max(dp[idx][state], fn(dp, prices, idx+1, 0) + prices[idx]);
    }
    return dp[idx][state];
}

// Time complexity: O(N)
// Space complexity: O(N)
int maxProfit(vector<int>& prices) {
    int n = (int) prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return fn(dp, prices, 0, 0);
}

int main() {
    // Test case 1
    vector<int> in1 = {7,1,5,3,6,4};
    int out1 = maxProfit(in1);
    cout << "out1: " << out1 << endl;

    // Test case 2
    vector<int> in2 = {1,2,3,4,5};
    int out2 = maxProfit(in2);
    cout << "out2: " << out2 << endl;

    // Test case 3
    vector<int> in3 = {7,6,4,3,1};
    int out3 = maxProfit(in3);
    cout << "out3: " << out3 << endl;
    return 0;
}