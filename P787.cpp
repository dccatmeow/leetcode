/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that 
there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.
*/

class Solution {
public:
int findCheapestPrice(int n, std::vector<std::vector<int>>& flights,
                       int src, int dst, int K) {

     int graph[n][n];
     memset(graph, 0, sizeof(graph));
     for (auto const& f : flights) {
         graph[f[0]][f[1]] = f[2];
     }

     // minimal cost from source to each node
     int minCost[n];
     std::fill(minCost, minCost+n, INT_MAX);

     // cost to source node from source node is 0
     auto q = std::queue<std::pair<int,int>>();
     q.push({src,0});
     minCost[src] = 0;

     // perform K+1 BFS propogration
     for (int i=0; i<=K; ++i) {
         int const m = q.size();
         if (m == 0) {
             break;
         }

         for (int j=0; j<m; ++j) {
             auto p = q.front();
             q.pop();
             for (int k=0; k<n; ++k) {
                 // if there is a flight from current city to city k
                 if (graph[p.first][k]) {
                     int newCost = p.second + graph[p.first][k];
                     if (k == dst) {
                         minCost[k] = std::min(minCost[k], newCost);
                     } else if (minCost[k] > newCost) {
                         // only push it to queue if we arrive city k
                         // with a lower cost from source city
                         q.push({k, newCost});
                         minCost[k] = newCost;
                     }
                 }
             }
         }
     }

     return minCost[dst] == INT_MAX ? -1 : minCost[dst];
 }
};
