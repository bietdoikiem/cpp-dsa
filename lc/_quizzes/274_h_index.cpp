#include <bits/stdc++.h>

using namespace std;

/**
 * Given an array of integers citations where citations[i] 
 * is the number of citations a researcher received for their ith paper, return the researcher's h-index.
 * 
 * According to the definition of h-index on Wikipedia: 
 * The h-index is defined as the maximum value of h such that the given researcher 
 * has published at least h papers that have each been cited at least h times.
 * 
 * Input:
 * 1 <= n <= 5000
 * 0 <= citations[i] <= 1000
*/


int hIndex(vector<int>& citations) {
    int n = (int) citations.size();
    sort(citations.begin(), citations.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = ans; j <= citations[i]; j++) {
            if (i + j - 1 < n) {
                ans = j;
            }
        }
    }
    return ans;
}

int main() {
    // Test 1
    vector<int> in1 = {3,0,6,1,5};
    int out1 = hIndex(in1);
    cout << "out1: " << out1 << endl; // 3

    // Test 2
    vector<int> in2 = {1,3,1};
    int out2 = hIndex(in2);
    cout << "out2: " << out2 << endl; // 1
    return 0;
}