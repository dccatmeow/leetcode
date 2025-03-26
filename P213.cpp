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
        int n=nums.size();
        if (n==1) return nums[0];
        int res1 = findMaxRob(0,nums[0],n-1, nums);
        int res2 = findMaxRob(0,0,n, nums);
        return max(res1,res2);
    }

    int findMaxRob(int tmp, int tmp1, int m, vector<int>& nums){
        for (int i=1;i<m;++i){
            // 0 is robbed, n-1 is not robbed 
            int res = max(tmp+nums[i], tmp1);
            // move 1 forward
            tmp = tmp1;
            tmp1 = res;
        }
        return max(tmp,tmp1);
    }
};
