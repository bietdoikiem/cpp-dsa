#include <bits/stdc++.h>

using namespace std;

int sumOfEncryptedInt(vector<int>& nums) {
    int n = (int) nums.size();
    vector<int> encryptedNums;
    for (int i = 0; i < n; i++) {
        string num = to_string(nums[i]);
        int m = (int) num.size();
        int max_num = 0;
        for (auto& nu: num) {
            max_num = max(max_num, nu-'0');
        }
        string encrypted_num;
        for (int j = 0; j < m; j++) {
            encrypted_num.push_back(max_num+'0');
        }
        encryptedNums.push_back(stoi(encrypted_num));
    }
    int sum = accumulate(encryptedNums.begin(), encryptedNums.end(), 0);
    return sum;
}

int main() {
    return 0;
}