/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. 
You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, 
then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // set boundary nums[0] = 1, nums[n+1]=1
         // calculate value from 1 to n
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        // dp[i][j] is the calculated max coin in [i,j]
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // initial condition length =1 cases
        for (int i=1; i<=n; ++i ){
            dp[i][i] = nums[i-1]*nums[i]*nums[i+1];
        }
        // iterate through with increasing length
        // j-i+1 = len
        for (int len=2; len<=n; ++len){
            for (int i=1; i<=n; ++i){
                int j = len-1+i;
                if (j>n){
                    // out of right boundary
                    continue;
                }
                for (int k=i; k<=j; ++k){
                    // last pop is k, the value for last pop is
                    // nums[k]*nums[i-1]*nums[j+1]
                    if (k == i){
                        dp[i][j] = max(dp[i][j], nums[k]*nums[i-1]*nums[j+1] + dp[k+1][j] );
                    }else if (k == j){
                        dp[i][j] = max(dp[i][j], dp[i][k-1] + nums[k]*nums[i-1]*nums[j+1]);
                    }else{
                        dp[i][j] = max(dp[i][j], dp[i][k-1] + nums[k]*nums[i-1]*nums[j+1] + dp[k+1][j] );
                    }
                }
            }
        }
        return dp[1][n];
    }
};
