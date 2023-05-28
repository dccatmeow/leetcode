// 1857. Largest Color Value in a Directed Graph
/*
DFS+memory
use large 2D vector instead of hash table with 1D vector

There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
Example 1:

Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
*/

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // build graph
        int n = colors.size();
        c = colors;
        if (!edges.size()){
            return 1;
        }
        g = vector<vector<int>>(n,vector<int>());
        for (auto e:edges){
            g[e[0]].push_back(e[1]);
        }
        // traverse graph, with visited flag, path for circle detection
        visited = vector<int>(n, -1);
        int res = 0;
        // 26 small letters represent colors
        dp = vector<vector<int>>(n,vector<int>(26));
        for (int i=0; i<n; ++i){
            vector<int> path;
            if (visited[i]==-1){
                traverse(i);
            }
            res = max(res, *max_element(dp[i].begin(), dp[i].end()) );
            if(isCyclic)return -1;
        }
        return res;
    }

    void traverse(int i){
        if (visited[i]==0){
            // find a circle
            isCyclic =true;
            return;
        }
        if (visited[i]==1) return;
        visited[i] = 0;// in progress
        for (auto e:g[i]){
            traverse(e);
            // compare all the colors in child e and current i
            // save the larger one in current i
            for (int j=0; j<26;++j){
                if (dp[i][j]<dp[e][j]){
                    dp[i][j] = dp[e][j];
                }
            }
        }   
        dp[i][c[i]-'a']++;
        visited[i] = 1;// in progress
    }
private:
    vector<vector<int>> g;
    vector<int> visited;// //-1 not visited, 0 in process, 1 done
    vector<vector<int>> dp;//dp[i] has a list of 26 values, tha max value for each colorif dfs starts from i
    string c;
    bool isCyclic = false;
};
