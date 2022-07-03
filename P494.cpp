/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int tmp(0);
        for (auto i:nums){
            tmp+=i;
        }
        // cannot get target
        if (abs(target)>tmp){
            return 0;
        }

        // i is including numbers from 0 to i
        // j is the sum, [-tmp, tmp], after offset is from 0 to 2*tmp
        // dp[i][j] store how many times this value occurred
        // dp[3][0] = 1, means sum 0-tmp has occurred once, for nums from 0,1,2,3 
        
        auto dp = vector<vector<int>>(n,vector<int>(2*tmp+1, 0));
        dp[0][nums[0]+tmp] = 1;
        dp[0][-nums[0]+tmp] += 1; // in case nums[0] is 0
        for(int i=1; i<n;++i){
            for (int j=-tmp; j<=tmp;++j){
                if (dp[i-1][j+tmp] > 0){ // only consider non zero dp element
                    // +nums[i] cases
                    dp[i][j+nums[i]+tmp] += dp[i-1][j+tmp];
                    // -nums[i] cases
                    dp[i][j-nums[i]+tmp] += dp[i-1][j+tmp];
                }
            }
        }
        return dp[n-1][target+tmp];
    }
};

// time complexity O(n*tmp)
// space complexity O(n*tmp)
