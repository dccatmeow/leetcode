/*
You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) { 
        // add a number to make last element in nums can be checked by all the logic
        nums.push_back(1002);
        // keep track fullfil of each position
        vector<int> dp(3,0);
        // next [pos0, pos1, pos2, ...]
        // first fill pos1 and pos2, then consider extend pos3...
        // because after satisfying the length >=3 restriction
        // extend existing sequence is always safer than restart a new one
        int current = nums[0];
        int count(0);
        for (auto i:nums){
            if (i == current){
                // calculate identical numbers i
                count++;
            }else{
                vector<int> next(3,0);
                if (dp[0]+dp[1]>count){
                    // i cannot fulfill pos1 and pos2
                    return false;
                }
                // calculate next
                // dp[0]   dp[1]   dp[2]
                // next[0] next[1] next[2]
                next[1] = dp[0];
                next[2] = dp[1];
                int left = count-dp[0]-dp[1];
                // extended third element can only based on previous dp[2]
                next[2] = next[2]+min(dp[2],left);
                // place rest of count in next[0]
                next[0] = count - next[1] - next[2];
                dp = move(next);
                
                // if not consecutive
                if(i!=current+1){
                    if(dp[0]!=0 || dp[1]!=0){
                        return false;
                    }else{
                        // reset every element in dp
                        std::fill(dp.begin(), dp.begin()+3, 0);
                    }
                }
                
                // reset count
                count = 1;
                current = i;
            }
        }
        return true;
    }
};
