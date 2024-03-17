#include <bits/stdc++.h>

using namespace std;

bool isSubstringPresent(string s) {
    int n = (int) s.size();
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    unordered_set<string> se;
    for (int i = 0; i + 2 <= n; i++) {
        string sub = s.substr(i, 2);
        se.insert(s.substr(i, 2));
    }

    for (int i = 0; i + 2 <= n; i++) {
        if (se.find(rev_s.substr(i, 2)) != se.end()) {
            return true;
        }
    }
    return false;
}


int main() {
    // Test 1
    string s1 = "leetcode";
    bool o1 = isSubstringPresent(s1);
    cout << "o1: " << o1 << endl;

    // Test 2
    string s2 = "abcba";
    bool o2 = isSubstringPresent(s2);
    cout << "o2: " << o2 << endl;

    // Test 3
    string s3 = "abcd";
    bool o3 = isSubstringPresent(s3);
    cout << "o3: " << o3 << endl;

    // Test 4
    string s4 = "ausoee";
    bool o4 = isSubstringPresent(s4);
    cout << "o4: " << o4 << endl;
    return 0;
}