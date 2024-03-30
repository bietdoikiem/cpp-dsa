
#include <bits/stdc++.h>

using namespace std;

int get_hash(vector<int>& arr) {
    int h = arr.size();
    for (auto &i : arr) {
        h ^= i + 0x9e3779b9 + (h << 6) + (h >> 2);
    }
    return h;
}

int main() {
    return 0;
}