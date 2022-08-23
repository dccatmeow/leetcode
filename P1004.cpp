/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // sliding window
        int l=0;
        // count flip number
        int c = 0;
        int res(0);
        // increment right boundary
        for (int r=0; r<nums.size();++r){
            // flip right if met with 0
            if (nums[r] == 0) {
                c++;
            }
            if (c>k){
                // exceed flip count, shift left
                while(nums[l]==1){
                    ++l;
                }
                ++l;
                --c;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
