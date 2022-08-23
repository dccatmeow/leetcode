/*
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that 
the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
*/

class Solution {
public:
    using pii = std::pair<int, int>;
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pii> data;
        // store pii (position, passenger)
        for (auto e:trips){
            // from
            data.push_back(pii(e[1], e[0]));
            // to
            data.push_back(pii(e[2], -e[0]));
        }
        auto comp = [](pii& p1, pii& p2){
            if (p1.first == p2.first){
                // let passenger take off first before on board
                return p1.second < p2.second;
            }
            return p1.first<p2.first;
        };
        sort(data.begin(), data.end(), comp);
        // find max passenger capacity needed
        int res(0);
        int tmp(0);
        for (auto e:data){
            tmp +=e.second;
            res = max(res, tmp);
        }
        return res<=capacity;
    }
};
