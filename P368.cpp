/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    //Dynamic programming
        //Given a sorted list [E,F,G]
        //if (h%G == 0), then [E,F,G,h]forms a new divisible subset
        
        // store the largest divisible subset in a vector dp, where
        //dp[i] represents the largest divisible subset that ends with nums[i]
        //dp[i] can be derived from dp[j] where j=0....i-1
        // if dp[i]%dp[j]=0, [dp[j],nums[i]] forms a new subset
        // If dp[j] is larger than current dp[i], then replace dp[i]
        // Time complexity O(N^2)
        // Space Complexity O(N^2)
        
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)
            return nums;
        
        // Sort. Time Complexity: O(nlogn)
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> dp(size, vector<int>());
        dp[0].push_back(nums[0]);
        //Calculate dp[i]
        for(int i=1; i<size; ++i){
            // form dp[i] on top of dp[j] that meets the requirement
            for(int j=0; j<i; ++j){
                if(nums[i] % nums[j] == 0 && dp[j].size()> dp[i].size())
                    dp[i] = dp[j];                
            }
            // Add nums[i] itself to dp[i]
            dp[i].push_back(nums[i]);
        }
        
        int largest_pos = 0;
        for(int i=0; i<size; ++i){
            if (dp[i].size() > dp[largest_pos].size())
                largest_pos = i;
        }
        
        return dp[largest_pos];
    }
};
