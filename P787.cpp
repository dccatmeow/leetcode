/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that 
there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman-Ford method
        vector<int> mem(n, 1e9);
        mem[src]=0;
        for (int i=0;i<k+1;++i){
            auto tmp = mem;
            for (auto& v:flights){
                int start = v[0];
                int term = v[1];
                int c = v[2];
                if (mem[start]!=1e9){
                    // update end stop in tmp, using start from mem. this round always using mem for start, then update term in tmp
                    tmp[term] = min(tmp[term], mem[start]+c);
                }
            }
            mem = tmp;
        }
        return mem[dst]==1e9? -1: mem[dst];
    }
};
// Time Complexity O(km)
// Space Complexity O(n)
