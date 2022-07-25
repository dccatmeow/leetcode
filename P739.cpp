/*
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.
Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int l = temperatures.size();
        vector<int> res(l);
        for (auto i=l-1; i>=0;--i){
            while(!s.empty() && temperatures[i]>=temperatures[s.top()]){
                s.pop();
            }
            if (s.empty()){
                res[i] = 0;
            }else{
                res[i] = s.top()-i;
            }
            s.push(i);
        }
        return res;
    }
};
