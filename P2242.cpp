TLE
/*
There is an undirected graph with n nodes, numbered from 0 to n - 1.

You are given a 0-indexed integer array scores of length n where scores[i] denotes the score of node i.
You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A node sequence is valid if it meets the following conditions:

There is an edge connecting every pair of adjacent nodes in the sequence.
No node appears more than once in the sequence.
The score of a node sequence is defined as the sum of the scores of the nodes in the sequence.

Return the maximum score of a valid node sequence with a length of 4. If no such sequence exists, return -1.

Example 1:
Input: scores = [5,2,9,8,4], edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
Output: 24
Explanation: The figure above shows the graph and the chosen node sequence [0,1,2,3].
The score of the node sequence is 5 + 2 + 9 + 8 = 24.
It can be shown that no other node sequence has a score of more than 24.
Note that the sequences [3,1,2,0] and [1,0,2,3] are also valid and have a score of 24.
The sequence [0,3,2,4] is not valid since no edge connects nodes 0 and 3.
*/

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int res(-1);
        int n = scores.size();
        // construct graph
        // only store top 3 scores for each node's neighbors
        // this will make sure we have largest 4 possible
        vector<vector<int>> g(n, vector<int>());
        for (auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        // priority_queue from smallest to largest
        auto comp = [scores](const int& a, const int& b){
            return scores[a]>scores[b];
        };
        // max size nx3
        for (auto v:g){
            priority_queue<int, vector<int>, decltype(comp)> q(comp);
            for (auto e:v){
                q.push(e);
                if (q.size() == 4){
                    q.pop();
                }
            }
            v.resize(q.size());
            for (int i=0; i<q.size(); ++i){
                v[i] = q.top();
                q.pop();
            }
        }
        // iterate through all the edges to find the top 4
        for (auto e:edges){
            // e[0], e[1], the other 2
            int cnt(0);
            for (auto p:g[e[0]]){
                if (p==e[0]||p==e[1]){
                    continue;
                }
                for (auto q:g[e[1]]){
                    if (q==e[0]||q==e[1]||p==q){
                        continue;
                    }
                    cnt = max(cnt, scores[p]+scores[q]);
                }
            }
            if (cnt!=0){
                cnt += scores[e[0]]+scores[e[1]];
                res = max(res, cnt);
            }
        }
        return res;
    }
};
