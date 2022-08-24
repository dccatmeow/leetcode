/*
There are n flights that are labeled from 1 to n.

You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti 
through lasti (inclusive) with seatsi seats reserved for each flight in the range.

Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.

Example 1:

Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // calculate all the event at n position
        // event[1]...event[n]
        vector<int> event(n+2, 0); 
        for (auto e:bookings){
            // event at e[0] add up
            // event at e[1]+1 reduced down
            event[e[0]] += e[2];
            event[e[1]+1] -= e[2];
        }
        // res[0]...res[n-1]
        vector<int> res(n, 0);
        int tmp(0);
        for (int i=0; i<n; ++i){
            tmp+=event[i+1];
            res[i] = tmp;
        }
        return res;
    }
};
