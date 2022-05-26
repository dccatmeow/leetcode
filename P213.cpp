/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // visited nums[0], not visited nums[n-1]
        int tmp1, tmp2, res;
        tmp1 = 0;
        tmp2 = nums[0];
        res = tmp2;
        for (int i=1; i<n-1; ++i){
            res = max(tmp1+nums[i], tmp2);
            tmp1 = tmp2;
            tmp2 = res;
        }
        int res1(0);
        tmp1 = 0;
        tmp2 = 0;
        // not visit nums[0]
        for (int i=1; i<n; ++i){
            res1 = max(tmp1+nums[i], tmp2);
            tmp1 = tmp2;
            tmp2 = res1;
        }
        return max(res, res1);
        
    }
};
