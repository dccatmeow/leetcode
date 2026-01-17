/*
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). 
You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) 
given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.
*/
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,INT_MAX));
        auto direction = vector<std::pair<int,int>>{{1,0},{0,1},{-1,0},{0,-1}};
        queue<vector<int>> q;
        q.push(vector<int>{0,0,0});
        visited[0][0] = 0;
        int step(0);
        while(!q.empty()){
            int sz = q.size();
            for (int qsz = 0; qsz<sz;++qsz){
                auto v = q.front();
                q.pop();
                int i=v[0];
                int j=v[1];
                int obstacle = v[2];
                
                if (i==m-1&&j==n-1){
                    // find target
                    return step;
                }
                // find shortest path in each direction
                for (auto [a,b]:direction){
                    a += i;
                    b += j;
                    int o = obstacle;
                    if (a<0||b<0||a>=m||b>=n){
                    // out of boundary
                        continue;
                    }
                    if (grid[a][b] ==1) {
                        o++;
                    }
                    if (o>k){
                        continue;
                    }
                    if (o>=visited[a][b]){
                        // visited
                        continue;
                    }
                    // set flag
                    visited[a][b] = o;
                    q.push(vector<int>{a,b,o});
                    
                    
                }
            }
            step++;
        }
        return -1;
    }
};
