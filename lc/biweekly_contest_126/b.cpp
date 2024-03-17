#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
    int m = (int) queries.size(), n = (int) nums.size();
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (ll) nums[i];
    }
    // Preprocess nums
    multiset<pair<int, int>> ms;
    for (int i = 0; i < n; i++) {
        ms.insert({nums[i], i});
    }
    vector<bool> marked(n, false);
    ll cost = 0;
    vector<ll> ans(m);
    // Process queries
    for (int i = 0; i < m; i++) {
        int markIdx = queries[i][0];
        int k = queries[i][1];
        if (!marked[markIdx]) {
            marked[markIdx] = true;
            ms.erase(ms.find({nums[markIdx], markIdx}));
            cost += (ll) nums[markIdx];
        }
        while (!ms.empty() && k > 0) {
            pair<int, int> top = *ms.begin();
            ll val = (ll) top.first;
            int idx = top.second;
            marked[idx] = true;
            cost += val;
            ms.erase(ms.begin());
            k--;
        }
        ans[i] = sum - cost;
    }
    return ans;
}

int main() {
    // Test 1
    vector<int> nums1 = {1,2,2,1,2,3,1};
    vector<vector<int>> queries1 = {{1,2},{3,3},{4,2}};
    vector<ll> o1 = unmarkedSumArray(nums1, queries1);
    
    cout << "o1: [ ";
    for (auto& it: o1) cout << it << ' ';
    cout << "]" << endl;

    return 0;
}