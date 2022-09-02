/*
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). 
You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) 
given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.
*/

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m=grid.size();
        int n=grid[0].size();
        bool visited[m][n][k+1];
        memset(visited, 0, sizeof(visited));
        
        // BFS
        int res(0);
        // queue with element {i, j, #of obstacle}
        queue<vector<int>> q;
        q.push(vector<int>{0,0,0});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0; i<sz; ++i){
                auto v = q.front();
                if (v[0] == m-1 && v[1] == n-1){
                    // reach [m-1, n-1]
                    return res;
                }
                //visited[v[0]][v[1]][v[2]] = true; only put visited flag at pop() in dijkistra
                q.pop();
                for (auto [x,y]:direction){
                    x += v[0];
                    y += v[1];
                    if (x<0 || y<0 || x>m-1 || y>n-1){
                        continue;
                    }
                    int z = v[2]+grid[x][y];
                    if (z>k || visited[x][y][z]){
                        continue;
                    }
                    q.push({x, y, z});
                    // BFS mark visited when it is pushed into queue
                    visited[x][y][z] = true;
                }
            }
            res++;
        }
        return -1;
    }
};
