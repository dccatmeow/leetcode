/*
934. Shortest Bridge
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
*/


class Solution {
public:
    
    using pii = pair<int,int>;
    vector<pii> direction{{1,0},{-1,0},{0,-1},{0,1}};
    
    int shortestBridge(vector<vector<int>>& grid) {
        // find first island DFS
        m=grid.size();
        n=grid[0].size();
        visited.resize(m,vector<bool>(n,false));
        bool flag = false;
        for (int i=0;i<m; ++i){
            if (flag){
                break;
            }
            for (int j=0; j<n;++j){
                if (grid[i][j]==1 && !flag){
                    // dfs through first island
                    dfs(grid, i, j);
                    flag = true;
                    break;
                }
            }
        }
        // BFS find shorted path
        int res(0);
        while(!queue.empty()){
            int sz= queue.size();
            for(int i=0; i<sz; ++i){
                auto [c,d] = queue.front();
                queue.pop();
                for (auto [p,q]:direction){
                    p+=c;
                    q+=d;
                    if (p>=0 && q>=0 && p<m && q<n){
                        if (grid[p][q] == 1){
                            return res;
                        }
                        if (grid[p][q]==2){
                            continue;
                        }
                        queue.push({p,q});
                        grid[p][q] =2;
                    }
                }
            }
            res++;
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (visited[i][j]){
            return;
        }else{
            visited[i][j] = true;
        }
        if (grid[i][j] == 0){
            return;
        }
        grid[i][j] = 2;
        bool cnt(false);
        for (auto [p,q]:direction){
            p+=i;
            q+=j;
            if (p>=0 && q>=0 && p<m && q<n){
                dfs(grid,p,q);
                if (grid[p][q] == 0){
                    cnt = true;
                }
            }
        }
        if (cnt){
            // boundary of island
            queue.push({i,j});
        }
    }
    private:
    int m;
    int n;
    vector<vector<bool>> visited;
    queue<pii> queue;
};
