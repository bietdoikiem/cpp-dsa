#include <bits/stdc++.h>

using namespace std;

// +Description:
// Build a largest palindromic number (in string) from the given string input below.
// NOTE: No leading zeroes
//
// +Input:
// num = "444947137"
//
// +Output:
// "7449447"
// 
// Thought process:
// 1. How we maintain larger number in order here?
// - A Palindrome is comprised of whether even frequencies of characters, or even freq + one odd (largest odd is preferred here)
// - We can use a max priority queue here with pq's key = (digit, frequency)
// - We will greedily use even frequencies of digits (bigger to smaller)
// - If number has odd frequencies -> we'll use f-1 frequencies and leave the remaining 1 for PQ to decide the largest odd to use in middle
//
// 2. What data structure we use to build the output number (in string) here?
// - We can just a list of characters here (aka string since string in C++ is mutable in O(1) for each append)

// Time complexity: O(nlogn)
// Space complexity: O(n)
string largestPalindromic(string num) {
    int n = (int) num.size();
    string ans;
    vector<int> freq(10, 0);
    for (int i = 0; i < n; i++) {
        freq[num[i]-'0']++;
    }
    priority_queue<pair<char, int>, vector<pair<char, int>>> pq;
    char largestOdd = '\0';
    for (int i = 0; i < 10; i++) {
        if (freq[i] == 0) continue;
        pq.push({i+'0', freq[i]});
    }
    while (!pq.empty()) {
        pair<char, int> top = pq.top();
        char c = top.first;
        int f = top.second;
        pq.pop();
        if (f % 2 == 0) {
            for (int i = 0; i < f/2; i++) {
                ans.push_back(c);
            }
        } else {
            for (int i = 0; i < (f-1)/2; i++) {
                ans.push_back(c);
            }
            if (c > largestOdd) {
                largestOdd = c;
            }         
        }
    }
    ans.erase(0, ans.find_first_not_of('0'));
    string rev = ans;
    reverse(rev.begin(), rev.end());
    if (largestOdd != '\0') {
        ans.push_back(largestOdd);
    }
    if (ans == "") return "0";
    ans += rev; // Symmetric palindromic structure
    return ans;
}

int main() {
    // Test case 1
    string in = "444947137";
    string out = largestPalindromic(in);
    cout << "out1: " << out << endl;

    // Test case 2
    in = "0003";
    out = largestPalindromic(in);
    cout << "out2: " << out << endl;

    // Test case 3
    in = "6006";
    out = largestPalindromic(in);
    cout << "out3: " << out << endl;

    // Test case 4
    in = "0000000000000000000000000000000000";
    out = largestPalindromic(in);
    cout << "out4: " << out << endl;
    return 0;
}