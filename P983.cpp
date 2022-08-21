/*
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. 
Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // dp
        vector<int> optCost(days.size(),0); 
        // days[0] has optCost[0], at least one day pass needed
        optCost[0] = min(min(costs[0], costs[1]), costs[2]);
        
        for(int idx=1;idx<days.size();++idx){
            // case 1: days[idx] is using 1 day pass
            int cost = optCost[idx-1] + costs[0];
            // case 2: day[idx] is the end of 7 day pass
           // find starting day of 7 day pass
            int tmp = upper_bound(days.begin(), days.end(), days[idx]-7) - days.begin();
            if (tmp > 0){
                // tmp is at least the second day in days
                cost = min(cost, optCost[tmp-1] + costs[1]);
            }else{
                cost = min(cost, costs[1]);
            }
            // case 3: day[idx] is the end of 30 day pass
            tmp = upper_bound(days.begin(), days.end(), days[idx]-30) - days.begin();
            if (tmp > 0){
                cost = min(cost, optCost[tmp-1] + costs[2]);
            }else{
                cost = min(cost, costs[2]);
            }
            optCost[idx] = cost;
        }
        return optCost[days.size()-1] ;
    }
    
    
};
