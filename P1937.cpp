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
        // res is the maxium value it can get from first row to current row i at column j [i][j]
        vector<long long> res(n,0);
        vector<long long> tmp = res;
        vector<long long> tmp1 = res;
        for (int i=0; i<m; ++i){
            // at row i, previous row is res
            // linear scan from left, only look at element from left
            // tmp stores the max value it can get
            // res: 5   7             8                4
            // tmp: 5 max(5-1,7)=7   max(7-1,8)=8   max(8-1,4)=7
            tmp[0] = res[0];
            for (int j=1; j<n; ++j){
                tmp[j] = max(tmp[j-1]-1, res[j]);
            }
            // scan from right
            tmp1[n-1] = res[n-1];
            for (int j=n-2; j>=0; --j){
                tmp1[j] = max(tmp1[j+1]-1, res[j]);
            }
            // find max from left and from right plus current element
            for (int j = 0; j<n; ++j){
                res[j] = max(tmp[j], tmp1[j])+points[i][j];
            }
        }
        long long res_final(0);
        for(auto i:res){
            res_final = max(i, res_final);
        }
        return res_final;
    }
};
