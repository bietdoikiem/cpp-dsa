#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
    int n = (int) height.size();
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[st.top()] < height[i]) {
            int top = st.top();
            st.pop();
            if (st.empty()) continue;
            int second = st.top();
            ans += (min(height[i], height[second]) - height[top]) * (i - second - 1);
        }
        st.push(i);
    }
    return ans;
}

int main() {
    // Test case 1
    vector<int> in1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    int out1 = trap(in1);
    cout << "out1: " << out1 << endl; // 6

    // Test case 2
    vector<int> in2 = {4,2,0,3,2,5};
    int out2 = trap(in2);
    cout << "out2: " << out2 << endl; // 9
    return 0;
}