/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto comp = [](vector<int> v1, vector<int> v2){
            // sort by first element increasingly
            // sort second element decreasingly
            if (v1[0] == v2[0]){
                return v1[1]>v2[1];
            }else{
                return v1[0]<v2[0];
            }
        };
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res;
        vector<int> prev;
        for (auto e:intervals){
            // initial condition
            if (prev.empty()){
                prev = e;
                continue;
            }
            // check if overlapping
            if (prev[1] >= e[0]){
                prev[1] = max(prev[1], e[1]);
            }else{
                // not overlapping
                res.push_back(prev);
                prev = e;
            }
        }
        res.emplace_back(prev);
        return res;
    }
};
