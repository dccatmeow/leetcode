/*
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle 
with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate 
of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. 
These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

Example 1:
Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
*/

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        // directed graph
        int n=bombs.size();
        // construct graph with adjacency list
        vector<vector<int>> g(n, vector<int>());
        for (int i=0; i<n; ++i){
            for (int j=i+1; j<n; ++j){
                // calculate if bomb j within bomb i's radius
                long long deltax = bombs[i][0] - bombs[j][0];
                long long deltay = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];
                // int 32 bit, long long 64 bit on 64 bit OS
                //*** avoid using long long * long long
                // i->j
                if (deltax*deltax+deltay*deltay<=r*r){
                    // j will be triggered
                    g[i].push_back(j);
                }
                // j->i
                r = bombs[j][2];
                if (deltax*deltax+deltay*deltay<=r*r){
                    // j will be triggered
                    g[j].push_back(i);
                }
            }
        }
        // dfs starting from each node to find the count of triggered downstream nodes
        int res(0);
        for (int i=0; i<n; ++i){
            vector<bool> visited(n,false);
            res = max(res, dfs(g, i, visited, 0));
        }
        return res;
    }
    int dfs(const vector<vector<int>>& g, int i, vector<bool>& visited, int cnt){
        if (visited[i]){
            return 0;
        }else{
            visited[i] = true;
        }
        for (auto j:g[i]){
            cnt+=dfs(g, j, visited, 0);
        }
        return cnt+1;
    }
private:
};
