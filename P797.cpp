/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, 
find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i 
(i.e., there is a directed edge from node i to node graph[i][j]).
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path{0};
        traverse(graph, 0, path);
        return res;
    }
    
    void traverse(vector<vector<int>>& graph, int i, vector<int> path){
        if (i == graph.size()-1){
            res.push_back(path);
            return;
        }
        if (graph[i].empty()){
            return;
        }
        for (auto j:graph[i]){
            path.push_back(j);
            traverse(graph, j, path);
            path.pop_back();
        }
    }
};
// time complexity O(edge) worst scenario O(2^(N-2)), each edge has exist or non-exist, 
// space complexity O(node) worst scenario
