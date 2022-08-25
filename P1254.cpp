/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally 
connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
*/

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // flood boundry
        for (int i=0; i<grid.size();++i){
            dfs(grid, i, 0);
            dfs(grid, i, (grid[0].size()-1));
        }
        
        for (int j=0; j<grid[0].size(); ++j){
            dfs(grid, 0, j);
            dfs(grid, (grid.size()-1), j);
        }
        int res=0;
        for (int i=1; i<(grid.size()-1);++i){
            for(int j =1; j<(grid[0].size()-1); ++j){
                if (grid[i][j] == 0){
                    // island
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
        
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i<0 || j<0 || i>=grid.size() || j >=grid[0].size()){
            return;
        }
        if (grid[i][j] == 1){
            // water
            return;
        }
        grid[i][j] = 1;
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
    }
};

// time complexity O(element in grid)
// space complexity O(1)
