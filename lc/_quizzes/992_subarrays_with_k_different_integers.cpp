#include <bits/stdc++.h>

using namespace std;

/**
 * LC no. 992
 * 
 * Given an integer array nums and an integer k, return the number of good subarrays of nums.
 * A good array is an array where the number of different integers in that array is exactly k.
 * For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
 * A subarray is a contiguous part of an array.
 */

// Time complexity: O(N*logK)
// Space complexity: O(K)
int subarraysWithKDistinct(vector<int>& nums, int k) {
    // a Window with k different integers
    int n = (int) nums.size();
    int cnt = 0;
    int l = 0;
    unordered_map<int, int> mp; // Mp frequency
    unordered_map<int, int> mpIdx; // Mp last index
    multiset<int> ms;
    // Find min endIdx where subarray is still valid?
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
        if (mpIdx.find(nums[i]) != mp.end()) {
            auto it = ms.find(mpIdx[nums[i]]);
            ms.erase(it);
        }
        mpIdx[nums[i]] = i;
        ms.insert(i);
        while (mp.size() > k && l <= i) {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) {
                mp.erase(nums[l]);
                ms.erase(ms.find(mpIdx[nums[l]]));
                mpIdx.erase(nums[l]);
            }
            l++;
        }
        if (mpIdx.size() == k) {
            // find min end idx efficiently?
            int minIdx = *ms.begin();
            cnt += (i - l + 1) - (i - minIdx);
        }
    }
    return cnt;
}

int main() {
    // Test 1
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    int ans = subarraysWithKDistinct(nums, k);
    cout << ans << endl; // 7

    // Test 2
    nums = {1,2,1,3,4};
    k = 3;
    ans = subarraysWithKDistinct(nums, k);
    cout << ans << endl; // 3
    return 0;
}