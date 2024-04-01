#include <bits/stdc++.h>

using namespace std;

/**
The string "PAYPALISHIRING" is written in a zigzag pattern on
a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows.
*/

// Time complexity: O(N)
// Space complexity: O(N) OR O(1) iff output answer does not count
string convert(string s, int numRows) {
    if (numRows == 1) return s;
    int delta = numRows + (numRows - 2);
    int n = (int) s.size();
    string ans;
    for (int i = 0; i < numRows; i++) {
        int j = i;
        while (j < n) {
            ans.push_back(s[j]);
            j += delta;
            if (i == 0 || i == numRows-1 || j - 2*i >= n) continue;
            ans.push_back(s[j - 2*i]);
        }
    }
    return ans;
}

int main() {
    return 0;
}