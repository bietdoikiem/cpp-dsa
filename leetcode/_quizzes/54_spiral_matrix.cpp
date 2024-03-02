#include<bits/stdc++.h>

using namespace std;

void traverse(vector<int>& ans, vector<vector<int>>& matrix, int sr, int er, int sc, int ec) {
    if (sr >= er || sc >= ec) return;

    // Left => Right
    for (int j = sc; j < ec; j++) {
        ans.push_back(matrix[sr][j]);
    }

    // Right => Bottom (Row-wise)
    for (int i = sr+1; i < er; i++) {
        ans.push_back(matrix[i][ec-1]);
    }

    // Avoid duplicate row print
    if (er - sr == 1) return;

    // Bottom => Left (Column-wise)
    for (int j = ec-2; j >= sc; j--) {
        ans.push_back(matrix[er-1][j]);
    }

    // Avoid duplicate row print
    if (ec - sc == 1) return;

    // Left => Up (row-wise)
    for (int i = er-2; i > sr; i--) {
        ans.push_back(matrix[i][sc]);
    }
    traverse(ans, matrix, sr+1, er-1, sc+1, ec-1);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;
    traverse(ans, matrix, 0, m, 0, n);
    return ans;
}


int main() {
    // Test case 1:
    vector<vector<int>> in1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> out1 = spiralOrder(in1); 
    cout << "out1: [ ";
    for (auto& it: out1) {
        cout << it << ' ';
    }
    cout << ']' << endl;;

    // Test case 2
    vector<vector<int>> in2 = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> out2 = spiralOrder(in2);
    cout << "out2: [ ";
    for (auto& it: out2) {
        cout << it << ' ';
    }
    cout << ']' << endl;;
    return 0;
}