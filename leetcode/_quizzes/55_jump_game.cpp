#include <bits/stdc++.h>

using namespace std;


// Time complexity: O(N)
// Space complexity: O(1)
bool canJump(vector<int>& nums) {
    int n = (int) nums.size();
    int dest = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (i + nums[i] >= dest) {
            dest = i;
        }
    }
    return dest == 0;
}

int main() {
    // Test 1
    vector<int> in1 = {2, 3, 1, 1, 4};
    bool out1 = canJump(in1);
    cout << "out1: " << boolalpha << out1 << endl; // true

    // Test 2
    vector<int> in2 = {3,2,1,0,4};
    bool out2 = canJump(in2);
    cout << "out2: " << boolalpha << out2 << endl; // false
    return 0;
}