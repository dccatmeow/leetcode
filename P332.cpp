/*
332. Reconstruct Itinerary
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //Eulerian path
        // build graph
        for (auto elem:tickets){
            g[elem[0]].insert(elem[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
    
    void dfs(string city){
        while (g[city].size()){
            auto elem = *g[city].begin();
            g[city].erase(g[city].begin());
            dfs(elem);
        }
        res.push_back(city);
    }
private:
    unordered_map<string, multiset<string>> g;
    vector<string> res;
};
