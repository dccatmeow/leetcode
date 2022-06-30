/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that 
the sum of elements in both subsets is equal.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sumV(0);
        // calculate presum
        for (auto i:nums){
            sumV+=i;
        }
        // calculate subset sum
        if (sumV%2 == 1){
            return false;
        }
        sumV = sumV/2;
        // dp[i][j] from 0,...i exist a subset such that their summate equals to j
        // j is from 0, sumV
        vector<vector<bool>> dp(nums.size(), vector<bool>(sumV+1, false));
        // i=0 boundary condition
        if (sumV<nums[0]){
            return false;
        }
        dp[0][nums[0]] = true;
        for (int i=1; i<nums.size();++i){
            dp[i][0] = false;
            dp[i][nums[i]] = true;
            for (int j=1; j<=sumV; ++j ){
                if (nums[i]>j){
                    // i cannot be in the set
                    dp[i][j] = dp[i-1][j];
                }else{
                    // either i is not in the subset or 
                    // i is in the subset its validity depends on dp[i-1][j-nums[i]]
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                } 
            }
        }
        return dp[nums.size()-1][sumV];
    }
};
