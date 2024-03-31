#include <bits/stdc++.h>

using namespace std;

int minimumDistance(vector<vector<int>>& points) {
    // Find all pair diff (give x1 > x2 && (y1 > y2 || y2 > y1)):
    // Opt1. max(xi + yi) - min(xi + yi)
    // Opt2. max(xi - yi) - min(xi - yi)
    // => max_manhattan_distance = max(opt1, opt2)
    int n = (int) points.size();
    int maxPos = INT_MIN, maxPosIdx = -1, minPos = INT_MAX, minPosIdx = -1;
    int maxNeg = INT_MIN, maxNegIdx = -1, minNeg = INT_MAX, minNegIdx = -1;
    for (int i = 0; i < n; i++) {
        int diffPos = points[i][0] + points[i][1];
        if (diffPos > maxPos) {
            maxPos = diffPos;
            maxPosIdx = i;
        }
        if (diffPos < minPos) {
            minPos = diffPos;
            minPosIdx = i;
        }
        int diffNeg = points[i][0] - points[i][1];
        if (diffNeg > maxNeg) {
            maxNeg = diffNeg;
            maxNegIdx = i;
        }
        if (diffNeg < minNeg) {
            minNeg = diffNeg;
            minNegIdx = i;
        }
    }

    vector<int> rIdx(2, -1);
    if (maxPos - minPos > maxNeg - minNeg) {
        rIdx[0] = maxPosIdx;
        rIdx[1] = minPosIdx;
    } else {
        rIdx[0] = maxNegIdx;
        rIdx[1] = minNegIdx;
    }

    // Greedy either remove min or max pos/neg indexes
    int ans = INT_MAX;
    for (int& idx: rIdx) {
        int maxPos = INT_MIN, minPos = INT_MAX;
        int maxNeg = INT_MIN, minNeg = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i == idx) continue;
            int diffPos = points[i][0] + points[i][1];
            maxPos = max(maxPos, diffPos);
            minPos = min(minPos, diffPos);
            int diffNeg = points[i][0] - points[i][1];
            maxNeg = max(maxNeg, diffNeg);
            minNeg = min(minNeg, diffNeg);
        }
        ans = min(ans, max(maxPos - minPos, maxNeg - minNeg));
    }
    return ans;
}

int main() {
    // Test 1
    vector<vector<int>> points = {{3,10},{5,15},{10,2},{4,4}};
    int ans = minimumDistance(points);
    cout << ans << endl; // 12
    return 0;
}