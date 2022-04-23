/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // monotonic stack
        // when element is smaller than stack top
        // pop stack top, save it
        // calculate the corresponding largest rectangle
        // by height x (largest on the right - largest in the left(stack top))
        
        // push back a 0 in height to allow all the results pop out from stack
        heights.push_back(0);
        stack<int> stk;
        int res(0);
        for(int i=0; i<heights.size(); ++i){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                // pop
                int tmp = stk.top();
                stk.pop();
                if (stk.empty()){
                    res = max(res, heights[tmp]*i);
                }else{
                    res = max(res, heights[tmp]*(i-stk.top()-1));
                }
            }
            stk.push(i);
        }
        return res;
    }
};
