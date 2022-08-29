/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). 
An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.
Example 1:
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
*/

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size();
        int n=grid2[0].size();
        int res=0;
        // flood all the island that does not satisfy grid1[i][j] is land
        for (int i = 0; i<m; ++i){
            for (int j=0; j<n;++j){
                if (grid2[i][j] == 1 && grid1[i][j] == 0){
                    // not a sub-island, flood it
                    dfs(grid2, i, j);
                }
            }
        }
        // dfs to count all the island left
        for (int i = 0; i<grid2.size(); ++i){
            for (int j=0; j<grid2[0].size();++j){
                if (grid2[i][j] == 1){
                    dfs(grid2, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (grid[i][j] == 0){
            // not in this island any more
            return;
        }
        // flood the land on current island
        grid[i][j] = 0;
        
        std::vector<std::pair<int,int>> diff{{i+1,j}, {i-1,j}, {i, j-1}, {i, j+1}};
        for (auto [i,j]:diff){
            if (i<0||j<0||i>=grid.size()||j>=grid[0].size()){
                continue;
            }
            dfs(grid, i, j);
        }
    }
};
