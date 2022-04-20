/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp(-10001);
        int res(-10001);
        for(auto i:nums){
            // find the max between continue add on previous value
            // or restart from i
            tmp = max(tmp+i, i);
            // previous value is saved in res
            res = max(res, tmp);
        }
        return res;
    }
};
