/*
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. 
For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) 
will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.

Example 1:

Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
*/
class Solution {
public:
long long maxPoints(vector<vector<int>>& points) {
    int m = points.size();
    int n = points[0].size();
    vector<long long> dp(n), newDp(n);
    
    // initialize first row
    for (int c = 0; c < n; c++) {
        dp[c] = points[0][c];
    }
    
    for (int r = 1; r < m; r++) {
        vector<long long> left(n), right(n);
        // dp[0], dp[1], dp[2],.... k
        //          c
        // left to right
        // dp[k] - (c-k) = dp[k]+k - c
        // calculate at c,max of above for all the k on the left
        left[0] = dp[0]; // k=0
        for (int c = 1; c < n; c++) {
            left[c] = max(left[c-1], dp[c] + c);
        }
        // right to left
        // dp[k] -(k-c) = dp[k]-k +c
        right[n-1] = dp[n-1] - (n-1);
        for (int c = n-2; c >= 0; c--) {
            right[c] = max(right[c+1], dp[c] - c);
        }
        // compute new dp
        for (int c = 0; c < n; c++) {
            newDp[c] = points[r][c] +
            max(left[c] - c, right[c] + c);
        }
        dp.swap(newDp);
    }
    return *max_element(dp.begin(), dp.end());
    }
};
//Time complexity O(mxn)
// space complexity O(n)
