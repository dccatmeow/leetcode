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
public:
    using pii = pair<int,int>;
    int orangesRotting(vector<vector<int>>& grid) {
        int res(0);
        queue<pii> q;
        int fresh(0);
        // find the rotten orange and push into priority queue
        for (int i=0; i<grid.size(); ++i){
            for (int j=0; j<grid[0].size(); ++j){
                pii p = pii(i,j);
                if (grid[i][j] == 2){
                    q.push(p);
                }else if (grid[i][j] ==1){
                    // count fresh tomatoes
                    fresh++;
                }
            }
        }
        // loop through all the rotten oranges
        while(!q.empty()){
            int n = q.size();
            bool flagUpdate(false);
            while(n!=0){
                auto tmp = q.front();
                q.pop();
                int i=tmp.first;
                int j=tmp.second;
                n--;
                if (grid[i][j] == 2){
                    // visit 4 direction fresh tomatoes
                    vector<pii> v{
                        pii(i-1, j),
                        pii(i+1, j),
                        pii(i, j-1),
                        pii(i, j+1)
                    };
                    for (auto p:v){
                        if (p.first>=0 && p.first<grid.size() && p.second>=0 && p.second<grid[0].size()){
                            if (grid[p.first][p.second] == 1){
                                grid[p.first][p.second] = 2;
                                q.push(p);
                                flagUpdate = true;
                                fresh--;
                            }
                        }
                    }
                    // visited this rotten orange, mark it as empty, no long need to visit here
                    grid[i][j] = 0;
                }
            } // end of while(n!=0)
            // this layer has update rotten oranges
            if (flagUpdate){
                res++;
            }
        } // end of while (q.empty())
        
        if (fresh == 0){
            return res;
        }else{
            return -1;
        }
    }
};
