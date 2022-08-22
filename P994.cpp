/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

*/

class Solution {
    using pii = std::pair<int, int>;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS
        std::queue<pii> q;
        int m = grid.size();
        int n = grid[0].size();
        int res(0); // count of layers in BFS
        int fresh(0);
        // first find the rotten orange and push it into queue
        // count fresh oranges
        for (int i=0; i<grid.size(); ++i){
            for (int j=0; j<grid[0].size();++j){
                if (grid[i][j] == 2){
                    q.push(pii(i,j));
                }else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        // loop through each layer using the length of queue
        vector<pii> w{pii(0,1), pii(0,-1), pii(-1,0), pii(1,0)};
        while(!q.empty()){
            bool freshOrangeAdded = false;
            int s = q.size();
            for (int sz=0; sz<s; ++sz){
                // loop through all the elements in this layer
                auto [i,j] = q.front();
                q.pop();
                for (auto [i1,j1]:w){
                    i1 += i;
                    j1 += j;
                    if (i1 <0 || i1>=m || j1<0 || j1>=n){
                        continue;
                    }
                    if (grid[i1][j1] == 1){
                        // fresh orange spotted
                        q.push(pii(i1,j1));
                        grid[i1][j1] = 0;
                        fresh--;
                        freshOrangeAdded = true;
                    }
                }
            }
            if (freshOrangeAdded){
                res++;
            }
        }
        
        if (fresh != 0){
            return -1;
        }
        
        return res;
    }
};
