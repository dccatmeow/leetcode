/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 
4-directionally adjacent square if and only if the elevation of both squares individually are at most t. 
You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

Example 1:

Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // Dijkistra
        auto comp=[](const vector<int>& v1, const vector<int>& v2){
            return v1[0]>v2[0];
        };
        // vector {maxtime need for water to arrive [x,y], x, y}
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> q(comp);
        q.push(vector<int>{grid[0][0],0,0});
        std::vector<std::pair<int,int>> diff{{0,1},{1,0},{-1,0},{0,-1}};
        int m = grid.size(); //square
        vector<vector<bool>> visited(m, vector<bool>(m, false));
        while(!q.empty()){
            auto v = q.top();
            q.pop();
            if (v[1]==m-1&&v[2]==m-1){
                return v[0];
            }
            
            visited[v[1]][v[2]] = true;
            for (auto [i,j]:diff){
                i += v[1];
                j+=v[2];
                if (i>=0 && j>=0 && i<m && j<m && !visited[i][j]){
                    // the max time the route needed is maxtime(next location, current location)
                    q.push(vector<int>{max(grid[i][j],v[0]), i, j});
                }
            }
        }
        return grid[0][0];
    }
};
