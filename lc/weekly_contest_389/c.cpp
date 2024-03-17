#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int fn(auto& dp, auto& cnt, int& k, int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (cnt[i] - cnt[j] > k) {
        dp[i][j] = min(cnt[i] - cnt[j] - k + fn(dp, cnt, k, i+1, j), cnt[j] + fn(dp, cnt, k, i, j-1));
    } else {
        dp[i][j] = fn(dp, cnt, k, i+1, j);
    }
    return dp[i][j];
}

int minimumDeletions(string word, int k) {
    vector<int> cnt(26, 0);
    for (int i = 0; i < word.size(); i++) {
        cnt[word[i]-'a']++;
    }
    sort(cnt.begin(), cnt.end(), greater<int>());
    int l = 0, r = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) break;
        r = i;
    }
    cnt.resize(r+1);
    vector<vector<int>> dp(r+1, vector<int>(r+1, -1));
    return fn(dp, cnt, k, l, r);
}

int main() {
    // Test case 1
    string word1 = "aabcaba";
    int k1 = 0;
    int o1 = minimumDeletions(word1, k1);
    cout << "o1: " << o1 << endl;

    // Test case 2
    string word2 = "dabdcbdcdcd";
    int k2 = 2;
    int o2 = minimumDeletions(word2, k2);
    cout << "o2: " << o2 << endl;

    // Test case 3
    string word3 = "aaabaaa";
    int k3 = 2;
    int o3 = minimumDeletions(word3, k3);
    cout << "o3: " << o3 << endl;
    return 0;
}