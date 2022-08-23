/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

class Solution {
public:
    int res = 0;
    int numEnclaves(vector<vector<int>>& grid) {
        
        // flood boundry
        for (int i=0; i<grid.size();++i){
            dfs(grid, i, 0);
            dfs(grid, i, grid[0].size()-1);
        }
        
        for (int j=0; j<grid[0].size();++j){
            dfs(grid, 0, j);
            dfs(grid, grid.size()-1, j);
        }
        
        // reset res
        res = 0;
        
        for (int i=1; i<grid.size()-1;++i){
            for (int j=1; j<grid[0].size()-1;++j){
                dfs(grid, i, j);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i<0 || j<0 || i>=grid.size()||j >=grid[0].size()){
            return;
        }
        if (grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        res++;
    };
};
