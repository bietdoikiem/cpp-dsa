#include <bits/stdc++.h>

using namespace std;

// Source: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/
/**
Given a rectangular pizza represented as a rows x cols matrix containing the following characters:
'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

For each cut you choose the direction: vertical or horizontal,
then you choose a cut position at the cell boundary and cut the pizza into two pieces.
If you cut the pizza vertically, give the left part of the pizza to a person.
If you cut the pizza horizontally, give the upper part of the pizza to a person.
Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple.
Since the answer can be a huge number, return this modulo 10^9 + 7.

Example 1:
Input: pizza = ["A..","AAA","..."], k = 3
Output: 3 
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
*/

int MOD = 1e9 + 7;
int m, n;

int fn(auto& dp, auto& pizza, auto& prefix, auto& prefixCol, int r, int c, int k) {
    if (k == 0) {
        return 1;
    }

    if (dp[r][c][k] != -1) {
        return dp[r][c][k];
    }

    ll cnt = 0;
    int totalCnt = 0;
    for (int i = r; i < m; i++) {
        totalCnt += prefix[i][n-1] - (c == 0 ? 0 : prefix[i][c-1]);
    }
    // Cut horizontally
    if (r != m-1) {
        int cntUp = 0;
        for (int i = r; i < m-1; i++) {
            cntUp += prefix[i][n-1] - (c == 0 ? 0 : prefix[i][c-1]);
            // If cntUp & rest of total is still >= 1 (both horizontal slices are valid)
            if (cntUp < 1 || totalCnt - cntUp < 1) continue;
            cnt += fn(dp, pizza, prefix, prefixCol, i+1, c, k-1);
        }
    }

    if (c != n-1) {
        // Cut vertically
        int cntLeft = 0;
        for (int j = c; j < n-1; j++) {
            cntLeft += prefixCol[j][m-1] - (r == 0 ? 0 : prefixCol[j][r-1]);
            // If cntLeft & rest of total is still >= 1 (both vertical slices are valid)
            if (cntLeft < 1 || totalCnt - cntLeft < 1) continue;
            cnt += fn(dp, pizza, prefix, prefixCol, r, j+1, k-1);
        }
    }
    return dp[r][c][k] = cnt % MOD;
}

int ways(vector<string>& pizza, int k) {
    m = pizza.size(), n = pizza[0].size();
    // slice horizontally, r = r' (r' > r)
    // slice vertically, c = c' (c' > c)
    int appleCnt = 0;
    vector<vector<int>> prefix(m, vector<int>(n, 0));
    vector<vector<int>> prefixCol(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int gain = pizza[i][j] == 'A' ? 1 : 0;
            appleCnt += gain;
            prefix[i][j] = j == 0 ? gain : gain + prefix[i][j-1];
        }
    }

    // No apple in the pie
    if (appleCnt == 0) return 0;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            int gain = pizza[i][j] == 'A' ? 1 : 0;
            prefixCol[j][i] = i == 0 ? gain: gain + prefixCol[j][i-1];
        }
    }
    vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k, -1)));
    return fn(dp, pizza, prefix, prefixCol, 0, 0, k-1);
}


int main() {
    return 0;
}