/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals 
you need to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // try to find the earliest end interval, remove the intervals overlapping this one
        // iterate this process, then it ends up with the max number of intervals not overlapping
        // thus, the removed intervals number is the minimum
        int res(0);
        auto comp = [](vector<int>& v1, vector<int>& v2){
            return (v1[1] < v2[1]);
        };
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> prev = intervals[0];
        for (int i=1; i<intervals.size();++i){
            if (intervals[i][0]<prev[1]){
                // current interval overlap prev
                res++;
            }else{
                // move to next interval
                // interval[0] prev(v)
                prev = intervals[i];
            }
        }
        return res;
    }
};
