/*
You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].


*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i(0), j(0);
        vector<vector<int>> res;
        int l, r;
        while(i!=firstList.size() && j!=secondList.size()){
            // find the possible crossing
            l = max(firstList[i][0], secondList[j][0]);
            r = min(firstList[i][1], secondList[j][1]);
            if (l<=r){
                res.push_back(vector<int>{l,r});
            }
            // advance the interval which is slower/to the left
            if (firstList[i][1] < secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
};
