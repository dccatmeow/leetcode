/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        priority_queue<int> q;
        q.push(0);
        for (int i=0; i<grid.size();++i){
            for(int j=0; j<grid[0].size(); ++j){
                if (grid[i][j]==1){
                    q.push(dfs(grid, i, j));
                }
            }
        }
        return q.top();
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return 0;
        }
        if (grid[i][j] == 0){
            return 0;
        }
        grid[i][j] =0;
        int temp =  1+dfs(grid, i-1, j)+dfs(grid, i+1, j)+dfs(grid, i, j-1)+dfs(grid, i, j+1);
        return temp;
    }
};

// time complexity O(elements)
// space complexity O(1) 
