#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
    if (x == 0) {
        return y;
    }
    return gcd(y % x, x); // y % x < x
}

int main() {
    int x = 9, y = 7;
    int ans = gcd(x, y);
    cout << "ans: " << ans << endl;
    return 0;
}