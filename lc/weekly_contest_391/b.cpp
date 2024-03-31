#include <bits/stdc++.h>

using namespace std;

/*
You are given two integers numBottles and numExchange.

numBottles represents the number of full water bottles that you initially have.
In one operation, you can perform one of the following operations:

- Drink any number of full water bottles turning them into empty bottles.
- Exchange numExchange empty bottles with one full water bottle.

Then, increase numExchange by one.

Note that you cannot exchange multiple batches of empty bottles for the same value of numExchange.
 For example, if numBottles == 3 and numExchange == 1, you cannot exchange 3 empty water bottles for 3 full bottles.


Input: numBottles = 13, numExchange = 6
Output: 15
Explanation: The table above shows the number of full water bottles, empty water bottles, the value of numExchange,
and the number of bottles drunk.
*/

int fn(auto& dp, int numExchange, int numBottles, int numEmpty) {
    if (dp[numExchange][numBottles][numEmpty] != -1) {
        return dp[numExchange][numBottles][numEmpty];
    }
    int res = 0;
    // Option 1: Drink empty
    if (numBottles > 0) {
        res = max(res, 1 + fn(dp, numExchange, numBottles - 1, numEmpty + 1));
    }
    // Option 2: Exchange
    if (numEmpty >= numExchange) {
        res = max(res, fn(dp, numExchange + 1, numBottles + 1, numEmpty - numExchange));
    }
    return dp[numExchange][numBottles][numEmpty] = res;
}

int maxBottlesDrunk(int numBottles, int numExchange) {
    vector<vector<vector<int>>> dp(105, vector<vector<int>>(101, vector<int>(101, -1)));
    return fn(dp, numExchange, numBottles, 0);
}

int main() {
    // Test 1
    int numBottles = 13;
    int numExchange = 6;
    int ans = maxBottlesDrunk(numBottles, numExchange);
    cout << ans << endl; // 15

    // Test 1
    numBottles = 10;
    numExchange = 3;
    ans = maxBottlesDrunk(numBottles, numExchange);
    cout << ans << endl; // 13
    return 0;
}