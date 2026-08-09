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

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // store val,i,j for grid[i][j]
        int n=grid.size();
        int res(0);
        auto visited = vector<vector<int>>(n,vector<int>(n,false));
        vector<std::pair<int,int>> direction{{1,0},{0,1},{-1,0},{0,-1}};
        pq.push({grid[0][0],0,0});
        visited[0][0] = true;
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            int val = v[0];
            int i=v[1];
            int j=v[2];
            res = max(res,val);
            if (i==n-1 && j==n-1){
                return res;
            }
            for (auto[p,q]:direction){
                p+=i;
                q+=j;
                if (p>=0&&p<n&&q>=0&&q<n&& !visited[p][q]){
                    pq.push({grid[p][q],p,q});
                    visited[p][q] = true;
                }
            }
        }
        return res;
    }
};
