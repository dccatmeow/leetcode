/*
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> v(n,0);
        for (int i=0; i<n; ++i){
            // convert string to int 
            v[i] = ((timePoints[i][0]-'0')*10+(timePoints[i][1]-'0'))*60+(timePoints[i][3]-'0')*10+(timePoints[i][4]-'0');
        }
        sort(v.begin(), v.end());
        // add first time at the end so we have the difference between last element and first element
        v.push_back(v[0]+24*60);
        int res(24*60);
        for (int i=0; i<v.size()-1; ++i){
            res = min(res, v[i+1] - v[i]);
        }
        return res;
    }
};
