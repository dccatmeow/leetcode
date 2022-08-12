/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. 
Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that 
the person labeled ai does not like the person labeled bi, 
return true if it is possible to split everyone into two groups in this way.

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
*/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        vector<bool> visited(n+1, false);
        vector<bool> color(n+1, false);
        for (auto i:dislikes){
            graph[i[0]].emplace_back(i[1]);
            graph[i[1]].emplace_back(i[0]);
        }
        for(int i = 1; i<=n;++i){
            if (visited[i]){
                continue;
            }
            if (!traverse(graph,visited, color, i)){
                return false;
            }
        }
        return true;
    }
    
    bool traverse(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& color, int current){
        visited[current] = true;
        for (auto e:graph[current]){
            if(visited[e]){
                // same color, dislike linked.
                if (color[current] == color[e]){
                    return false;
                }
            }else{
                color[e] = !(color[current]);
                if (!traverse(graph, visited, color, e)){
                    return false;
                }    
            }
        }
        return true;
    }
};
