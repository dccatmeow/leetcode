/*
There are n cities labeled from 1 to n. You are given the integer n and an array connections where 
connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. 
If it is impossible to connect all the n cities, return -1,

The cost is the sum of the connections' costs used.
*/

class Solution {
public:
    vector<int> parent;
    int minimumCost(int n, vector<vector<int>>& connections) {
        // minimum spanning tree, use Kruskal 
        // sort edge
        auto comp = [](const vector<int>& a, const vector<int>& b){
             return a[2]<b[2];
         };
        sort(connections.begin(), connections.end(), comp);
        
        // track total edge added to MST
        int count = 0;
        // track total cost
        int cost = 0;
        // initialize parent
        for (int i=0; i<=n; ++i){
            // 1...n
            parent.push_back(i);
        }
        
        // loop through edges
        for (auto i:connections){
            if (findP(i[0]) == findP(i[1])){
                // same parent
                continue;
            }else{
                // new edge needed
                unionP(i[0], i[1]);
                count++;
                cost = cost+i[2];
            }
        }
        if (count == n-1){
            // edge number is n-1 with n nodes
            return cost;
        }else{
            return -1;
        }
    }
    
    int findP(int c){
        if (parent[c]!= c){
            return findP(parent[c]);
        }
        return c;
    }
    
    void unionP(int idx1, int idx2){
        auto p1 = findP(idx1);
        auto p2 = findP(idx2);
        if (p1 < p2){
            parent[p2] = p1; 
        }else{
            parent[p1] = p2;
        }
    }
};
