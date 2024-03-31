#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Time complexity: O(N)
// Space complexity: O(1)
ll countSubarrays(vector<int>& nums, int minK, int maxK) {
    int n = (int) nums.size();
    int maxIdx = -1, minIdx = -1;
    int maxSoFar = INT_MIN, minSoFar = INT_MAX;
    ll cnt = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == minK) minIdx = i;
        if (nums[i] == maxK) maxIdx = i;
        maxSoFar = max(maxSoFar, nums[i]);
        minSoFar = min(minSoFar, nums[i]);
        if (minSoFar < minK || maxSoFar > maxK) {
            maxSoFar = INT_MIN;
            minSoFar = INT_MAX;
            l = i + 1;
        } else if (minSoFar == minK && maxSoFar == maxK) {
            cnt += (i - l + 1) - (i -  min(maxIdx, minIdx));
        }
    }
    return cnt;
}

int main() {
    return 0;
}