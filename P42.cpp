/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> lw(n,0); // left wall height
        int wh(0); // wall height
        // loop from left to right to find the tallest wall 
        // on the left side of current node
        for (int i=1; i<n; ++i){
            wh = max(wh, height[i-1]);
            lw[i] = wh;
        }
        // reset
        wh = height[n-1];
        int res(0);
        // loop from right to left to find the tallest wall 
        // on the right side of current node
        for (int i=n-2; i>0; --i){
            wh = max(wh, height[i+1]);
            res += max(0, (min(lw[i], wh) - height[i])); 
        }
        return res;
    }
};
