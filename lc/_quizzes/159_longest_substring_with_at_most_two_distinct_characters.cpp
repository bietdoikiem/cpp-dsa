#include <bits/stdc++.h>

using namespace std;

/**
 * Given a string s, return the length of the longest 
   substring that contains at most two distinct characters.
 */

int lengthOfLongestSubstringTwoDistinct(string s) {
    int n = (int) s.size();
    int ans = 0;
    int l = 0;
    unordered_map<char, int> freq;
    for (int i = 0; i < n; i++) {
        freq[s[i]]++;
        while (freq.size() > 2 && l <= i) {
            freq[s[l]]--;
            if (freq[s[l]] == 0) freq.erase(s[l]);
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    return ans;
}

int main() {
    // Test 1
    string s = "eceba";
    int ans = lengthOfLongestSubstringTwoDistinct(s); // 3
    cout << ans << endl;

    // Test 2
    s = "ccaabbb";
    ans = lengthOfLongestSubstringTwoDistinct(s); // 5
    cout << ans << endl;
    return 0;
}