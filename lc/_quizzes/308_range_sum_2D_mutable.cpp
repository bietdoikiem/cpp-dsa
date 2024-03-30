#include <bits/stdc++.h>

using namespace std;

/**
 * NOTE: Fenwick Tree is 1-based index data structure.
 * Please make your data is 1-based index already with the sufficient size when initializing the tree.
 */
template<typename T>
class FenwickTree {
public:
    int size;
    vector<T> tree;

    FenwickTree(int _size) {
        size = _size;
        tree = vector<T>(size + 1, 0);
    }

    int query(int idx) {
        T res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & (-idx);
        }
        return res;
    }

    void update(int idx, T delta) {
        while (idx < size) {
            tree[idx] += delta;
            idx += idx & (-idx);
        }
    }
};


class NumMatrix {
public:
    int m, n;
    vector<FenwickTree<int>> trees;
    vector<vector<int>> matrix;

    NumMatrix(vector<vector<int>>& _matrix) {
        matrix = _matrix;
        m = matrix.size();
        n = matrix[0].size();
        trees = vector<FenwickTree<int>>(m, FenwickTree<int>(n + 1));
        buildFenwick();
    }
    
    void update(int row, int col, int val) {
        int delta = val - matrix[row][col];
        matrix[row][col] = val;
        trees[row].update(col + 1, delta);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int curSum = 0;
        for (int i = row1; i <= row2; i++) {
            curSum += trees[i].query(col2 + 1) - trees[i].query(col1);
        }
        return curSum;
    }

private:
    void buildFenwick() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                trees[i].update(j + 1, matrix[i][j]);
            }
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    return 0;
}