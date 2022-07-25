/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, 
a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, 
vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. 
Return the minimum time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
*/

// Dijkstra
class Solution {
public:
    using pii=pair<int, int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create graph 
        int count = 0;
        vector<bool> visited(n+1, false);
        vector<vector<vector<int>>> graph(n+1, vector<vector<int>>());
        for(auto i:times){
            graph[i[0]].push_back(i);
        }
        // create queue pii(node, distance to k)
        auto comparator = [](pii l, pii r){
            return l.second > r.second;
        };
        priority_queue<pii, vector<pii>, decltype(comparator)> q(comparator);
        q.push(pii(k,0));
        while(!q.empty()){
            auto [node, d] = q.top();
            q.pop();
            if (!visited[node]){
                count++;
                visited[node] = true;
            }else{
                continue;
            }
            if (count == n){
                // visited all the node
                return d;
            }
            for (auto i:graph[node]){
                q.push(pii(i[1], i[2]+d));
            }
        }
        return -1;
    }
};
// time complexity O(ElogV)
// space complexity O(E)
