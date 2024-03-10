#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int size) {
        parent.assign(size, 0);
        for (int i = 0; i < size; i++) parent[i] = i;
        rank.assign(size, 1);
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
bool equationsPossible(vector<string>& equations) {
    int n = (int) equations.size();
    DSU d1(26);
    for (int i = 0; i < n; i++) {
        char x = equations[i][0];
        string op = equations[i].substr(1, 2);
        char y = equations[i][equations[i].size()-1];
        if (op == "==") {
            d1.unite(x-'a', y-'a');
        }
    }
    for (int i = 0; i < n; i++) {
        char x = equations[i][0];
        string op = equations[i].substr(1, 2);
        char y = equations[i][equations[i].size()-1];
        if (op == "!=") {
            if (d1.find(x-'a') == d1.find(y-'a')) return false;
        }
    }
    return true;
}


int main() {
    // Test 1
    vector<string> t1 = {"a==b","b!=a"}; // Output: false
    bool o1 = equationsPossible(t1);
    cout << "o1: " << o1 << endl;

    // Test2
    vector<string> t2 = {"b==a","a==b"}; // Output: true
    bool o2 = equationsPossible(t2);
    cout << "o2: " << o2 << endl;

    return 0;
}