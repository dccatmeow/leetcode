/*
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
*/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // first element increasing sort and second element decreasing sort
        int res = intervals.size();
        auto comp = [](vector<int>& v1, vector<int>& v2){
            if (v1[0]==v2[0]){
                return v1[1]>v2[1];
            }else{
                return v1[0]<v2[0];
            }
        };
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> prev;
        for (auto e:intervals){
            if (prev.empty()){
                prev = e;
                continue;
            }
            // find the covered case
            if (prev[0] <= e[0] && e[1] <= prev[1]){
                res--;
                continue;
            }
            if (prev[1] < e[1]){
                prev = e;
            }
        }
        return res;
    }
};
