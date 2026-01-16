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
        vector<vector<int>> res;
        auto comp = [](vector<int>& v1, vector<int>& v2){
            if (v1[0]==v2[0]){
                return v1[1]<v2[1];
            }
            return v1[0]<v2[0];
        };
        // sort the vector based on first element nlogn
        sort(intervals.begin(), intervals.end(), comp);
        // merge overlap linear
        auto tmp = intervals[0];
        for (int i=1; i<intervals.size();++i){
            if (intervals[i][0]>tmp[1]){
                //non-overlap
                res.push_back(tmp);
                tmp = intervals[i];
            }else if (intervals[i][1]> tmp[1]){
                // overlap and extend tmp
                tmp[1] = intervals[i][1];
            }
        }
        res.push_back(tmp);
        return res;
    }
};
