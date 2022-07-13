/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int,int> m;
        int res(0);
        // set m[0], this is when key1-k==0, key1 is a solution
        m[0] = 1;
        int sum(0);
        // create a map for all the presum value and corresponding count
        for (int i=0; i<nums.size(); ++i){
            // the goal is to find key1 - key2 = k
            // key1
            sum = sum+nums[i];
            // find if key2 is in the map
            if (m.count(sum-k)){
                // key2 exist, add the count of key2 in res
                res = res+m[sum-k];
            }
            // add count of key1
            m[sum]++;
        }
        return res;
    }
};
