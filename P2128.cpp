/*
You are given an m x n binary matrix grid.

In one operation, you can choose any row or column and flip each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Return true if it is possible to remove all 1's from grid using any number of operations or false otherwise.

Example 1:

Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
Output: true
Explanation: One possible way to remove all 1's from grid is to:
- Flip the middle row
- Flip the middle column
*/

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        // flip all the 1's in first row
        // first row should have all 0,
        // if this grid has an answer then the rest of rows
        // should have all 1 or all 0, because no column operation can be performed.
        int m=grid.size();
        int n=grid[0].size();
        for (int j=0; j<n; ++j){
            if (grid[0][j] == 1){
                for (int i=0; i<m; ++i){
                    grid[i][j] = grid[i][j]^1;
                }
            }
        }
        for (int i=1; i<m; ++i){
            for (int j=1; j<n;++j){
                if (grid[i][j]!=grid[i][0]){
                    // not all 0 or all 1
                    return false;
                }
            }
        }
        return true;
    }
};
