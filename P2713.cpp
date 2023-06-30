/*
Given a 1-indexed m x n integer matrix mat, you can select any cell in the matrix as your starting cell.

From the starting cell, you can move to any other cell in the same row or column, but only if the value of the destination cell is strictly greater than the value of the current cell. You can repeat this process as many times as possible, moving from cell to cell until you can no longer make any moves.

Your task is to find the maximum number of cells that you can visit in the matrix by starting from some cell.

Return an integer denoting the maximum number of cells that can be visited.
*/

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // sort based on value
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j){ 
                mp[mat[i][j]].push_back(make_pair(i, j));
            }
        }

        vector<int> row(m, 0), col(n, 0), tmpR(m), tmpC(n);
        // iterate through all the values from smallest
        for (auto &[k, v]: mp) {
            for (auto &[x, y]: v) {
                // jump in vertical or horizontal
                // row[x] is the max steps in the row it can jump before add x
                // this considered all old paths
                // use temporary row to avoid identical value in the same row
                int s = max(row[x], col[y]);
                tmpR[x] = max(tmpR[x], s + 1);
                tmpC[y] = max(tmpC[y], s + 1);
            }
            // write updated x row and y column
            for (auto &[x, y]: v) {
                row[x] = tmpR[x];
                col[y] = tmpC[y];
            }
        }
        return *max_element(col.begin(), col.end());
    }
};
