#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll countSubstrings(string s, char c) {
    ll cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            cnt++;
        }
    }
    return cnt * (cnt + 1) / 2; 
}

int main() {
    // Test 1
    string s1 = "abada";
    char c1 = 'a';
    ll o1 = countSubstrings(s1, c1);
    cout << "o1: " << o1 << endl;

    // Test 2
    string s2 = "zzz";
    char c2 = 'z';
    ll o2 = countSubstrings(s2, c2);
    cout << "o2: " << o2 << endl;

    return 0;
}