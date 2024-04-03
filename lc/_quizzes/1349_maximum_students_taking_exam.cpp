#include <bits/stdc++.h>

using namespace std;

/*
Given a m * n matrix seats  that represent seats distributions in a classroom.
If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.

Students can see the answers of those sitting next to the left, right, upper left and upper right,
but he cannot see the answers of the student sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible.

Students must be placed in seats in good condition.

Example 1:
Input: seats = [["#",".","#","#",".","#"],
                [".","#","#","#","#","."],
                ["#",".","#","#",".","#"]]
Output: 4
Explanation: Teacher can place 4 students in available seats so they don't cheat on the exam. 
*/

bool isSet(int mask, int idx) {
    return mask & (1 << idx);
}

bool isRowValid(auto& seats, int r, int mask) {
    // What to check?
    // Check if previous i-1 bit is off && next bit (i+1) is off.
    int n = seats[r].size();
    for (int i = 0; i < n; i++) {
        if (!isSet(mask, i)) continue;
        if (seats[r][i] == '#') return false; // If broken seat
        if (i > 0 && isSet(mask, i-1)) return false; // If previous bit is ON -> invalid
        if (i < n-1 && isSet(mask, i+1)) return false; // If next bit is ON -> invalid
    }
    return true;
}

bool isRowCheatable(auto& seats, int curMask, int prevMask) {
    int n = seats[0].size();
    for (int i = 0; i < n; i++) {
        if (!isSet(curMask, i)) continue;
        if (i > 0 && isSet(prevMask, i-1)) return false;
        if (i < n-1 && isSet(prevMask, i+1)) return false;
    }
    return true;
}

// {i: current row ith, mask: previous row mask}
int fn(auto& dp, auto& seats, int r, int mask) {
    // Time complexity: O(N * 2^M * 2^M * M)
    // N iterate through all rows, M iteration check each columns validity
    // Generate all possible subset, remember to check '#' && check mask collision (i+1, i-1)
    if (r == seats.size()) {
        return 0;
    }
    if (dp[r][mask] != -1) {
        return dp[r][mask];
    }
    // Generate all possible subsets of current row
    int n = seats[0].size();
    int res = 0;
    for (int newMask = 0; newMask < (1 << n); newMask++) {
        if (!isRowValid(seats, r, newMask)) continue;
        if (!isRowCheatable(seats, newMask, mask)) continue;
        int goodSeats = __builtin_popcount(newMask); 
        res = max(res, goodSeats + fn(dp, seats, r+1, newMask));
    }
    return dp[r][mask] = res;
}

int maxStudents(vector<vector<char>>& seats) {
    int m = seats.size(), n = seats[0].size();
    vector<vector<int>> dp(m, vector<int>(256, -1));
    return fn(dp, seats, 0, 0);
}

int main() {
    return 0;
}