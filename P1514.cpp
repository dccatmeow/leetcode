/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] 
is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

Example 1:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
*/

class Solution {
public:
    using pid = std::pair<int, double>;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // create graph
        vector<vector<pid>> g(n, vector<pid>()); 
        for (int i=0; i<edges.size(); ++i){
            g[edges[i][0]].push_back(pid(edges[i][1], succProb[i]));
            g[edges[i][1]].push_back(pid(edges[i][0], succProb[i]));
        }
        // Dijkistra
        auto comp = [](pid const& v1, pid const& v2){
            return v1.second < v2.second;
        };
        vector<bool> visited(n, false);
        priority_queue<pid, vector<pid>, decltype(comp)> p(comp);
        p.push(pid(start, 1));
        while(!p.empty()){
            auto [node, prob] = p.top();
            p.pop();
            visited[node] = true; // MARK: label visited after pop
            if (node == end){
                return prob;
            }
            for (auto v: g[node]){
                if(visited[v.first]){
                    continue;
                }else{
                    
                    p.push(pid(v.first, v.second*prob));
                }
            }
        }
        return 0;
    }
};
