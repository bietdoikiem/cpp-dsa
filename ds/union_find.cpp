#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
    vector<int> par, sz;

    UnionFind(int n) {
        par.assign(n, 0);
        for (int i = 0; i < n; i++) par[i] = i;
        sz.assign(n, 1);
    }

    int find(int v) {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return;
        };
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = par[x];
        sz[x] += sz[y];
    }
};

int main() {
    UnionFind uf(10);
    return 0;
}