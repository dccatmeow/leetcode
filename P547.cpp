/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, 
and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, 
and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/
class Solution {
public:
    // traverse a graph
    void traverse(vector<vector<int>>& M, vector<bool>& visited, int idx){
        visited[idx] = true;
        int n= M.size();
        for (int i = 0; i < n; ++i){
            // loop through all the unvisited neighbour of idx
            if (!visited[i] && M[idx][i]){
                traverse(M, visited, i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        int res(0);
        vector<bool> visited(n,false);
        for (int i=0; i<n; i++){
            if (!visited[i]){
                // visit unvisited node
                traverse(M, visited, i);
                res++;
            }
        }
        return res;
    }    
};
