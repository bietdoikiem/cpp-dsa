#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/**
 * Example 1:

Input: nums = [0,1,1,1]

Output: 5

Explanation:

The following sub-arrays are alternating: [0], [1], [1], [1], and [0,1].
*/

ll countAlternatingSubarrays(vector<int>& nums) {
    int n = (int) nums.size();
    ll cnt = 0;
    int l = -1;
    for (int i = 0; i < n; i++) {
        if (l == -1) {
            cnt += 1;
            l = 0;
            continue;
        }
        if (nums[i] != nums[i-1]) {
            cnt += (i - l + 1);
        } else {
            cnt += 1;
            l = i;
        }
    }
    return cnt;
}

int main() {
    // Test 1
    vector<int> nums = {0,1,1,1};
    int ans = countAlternatingSubarrays(nums); // 5
    cout << ans << endl;

    // Test 2
    nums = {1,0,1,0};
    ans = countAlternatingSubarrays(nums); // 2
    cout << ans << endl;
    return 0;
}