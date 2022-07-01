/*
Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto comp = [](vector<int>&v1, vector<int>&v2){
            return v1[1]<v2[1];
        };
        sort(points.begin(), points.end(), comp);
        int prev = points[0][1];
        int res(1);
        for (int i=1; i<points.size(); ++i){
            if (points[i][0] <= prev){
            }else{
                prev = points[i][1];
                res++;
            }
        }
        return res;
    }
};
