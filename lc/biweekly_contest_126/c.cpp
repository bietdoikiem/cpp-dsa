#include <bits/stdc++.h>

using namespace std;

string minimizeStringValue(string s) {
    int n = (int) s.size();
    vector<int> cnt(26, 0);
    multiset<pair<int, char>> ms;
    // Pre-populate characters
    for (int i = 0; i < 26; i++) {
        ms.insert({0, i+'a'});
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            ms.erase(ms.find({cnt[s[i]-'a'], s[i]}));
            cnt[s[i]-'a']++;
            ms.insert({cnt[s[i]-'a'], s[i]});
        }
    }
    vector<char> reps;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            pair<int, char> top = *ms.begin();
            int c = top.first;
            char ch = top.second;
            cnt[ch-'a'] = c + 1;
            reps.push_back(ch);
            ms.erase(ms.begin());
            ms.insert({cnt[ch-'a'], ch});
        }
    }

    sort(reps.begin(), reps.end());
    string ans; 
    int repIdx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            ans.push_back(s[i]);
        } else {
            ans.push_back(reps[repIdx]);
            repIdx++;
        }
    }
    return ans;
}    

int main() {
    // Test 1
    string s1 = "???";
    string o1 = minimizeStringValue(s1);
    cout << "o1: " << o1 << endl;
    return 0;
}