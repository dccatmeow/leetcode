/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        for (int i=0; i<grid.size(); ++i){
            for (int j=0; j<grid[0].size();++j){
                if (grid[i][j] == '1'){
                    // find an island
                    res++;           
                    dfs(grid, i, j);
                }
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        // use dfs to find all the connected "1" to grid[i][j] and flood it with "0"
        // boundary condition
        if (i<0 || j<0 || i>=grid.size() || j>= grid[0].size()){
            return;
        }
        if (grid[i][j]=='0'){
            return;
        }
        // flood it
        grid[i][j] = '0';
        dfs(grid, i-1,j);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
    }
};
// time complexity O(grid.size()xgrid[0].size());
// space complexity O(1)
