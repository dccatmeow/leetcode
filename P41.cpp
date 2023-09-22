/*
41. First Missing Positive

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool flag = false;
        // check case of 1
        for (auto c:nums){
            if (c==1){
                // exist 1
                flag = true;
                break;
            }
        }
        if (!flag){
            return 1;
        }
        // remove inavalid number, repleace it with -1
        int n=nums.size();
        for (int i=0; i<nums.size();++i){
            if (nums[i]<1 || nums[i]>n){
                nums[i]=1;
            }
        }
        // label existing number to location with negative sign
        for (int i=0; i<nums.size();++i){
            // find index for numbers to label
            int idx;
            if (nums[i]<0){
                idx = -nums[i]-1;
                
            }else{
                idx = nums[i]-1;
            }
            // mark position negative
            if (nums[idx]>0){
                nums[idx] = -nums[idx];
            }
        }
        // find the first positive number
        for (int i=1; i<nums.size();++i){
            if (nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};
