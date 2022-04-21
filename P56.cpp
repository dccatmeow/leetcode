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
        if (intervals.size() == 1){
            return intervals;
        }
        // comparator sort from small to large
        // if first element is identical, then sort second element from large to small
        auto comp=[](vector<int>& v1, vector<int>& v2){
            if (v1[0] == v2[0]){
                return v1[1]>v2[1];
            }
            return v1[0]<v2[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res;
        vector<int> tmp = intervals[0];
        for (auto v:intervals){
            if (tmp == v){
                // first element
                continue;
            }
            if (tmp[1]>=v[0]){
                // overlap, merge
                tmp[1] = max(tmp[1], v[1]);
            }else{
                //not overlap, push tmp to res
                res.push_back(tmp);
                tmp = v;
            }
        }
        // push back last vector
        res.push_back(tmp);
        return res;
    }
};
