/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of distinct islands.
*/
class Solution {
public:
    string temp;
    unordered_set<string> res;
    int numDistinctIslands(vector<vector<int>>& grid) {
        for (int i=0;i<grid.size();++i){
            for (int j=0; j<grid[0].size();++j){
                if (grid[i][j] ==1){
                    // island id is always starts with 0
                    dfs(grid, i, j, '0');
                    res.insert(temp);
                    temp.clear();
                }
            }
        }
        
        return res.size();
    }
    
    void dfs(vector<vector<int>>&grid, int i, int j, char id){
        temp.push_back(id);
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return;
        }
        
        if (grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i-1, j, '1');
        dfs(grid, i+1, j, '2');
        dfs(grid, i, j-1, '3');
        dfs(grid, i, j+1, '4');
        
        
    }
};
