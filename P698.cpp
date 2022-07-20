/*
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sumN(0);
        for (auto i:nums){
            sumN+=i;
        }
        if (sumN%k !=0){
            // cannot devide into k bucket
            return false;
        }
        int avg = sumN/k;
        sort(nums.begin(), nums.end(), greater());
        // nums is avg,..., avg, nums[i], .... nums[n-1]
        int i=0;
        // single element cannot be greater than avg
        if (nums[0]>avg){
            return false;
        }
        // pass avg
        while(nums[i] == avg){
            ++i;
        }
        vector<int> bucket(k-i, 0);
        return bt(nums, bucket, i, avg);
    }
    bool bt(vector<int>& nums, vector<int>& bucket, int i, int avg){
        // back track trying all the possible combination
        if (i == nums.size()){
            // find a solution as i reach the end of nums
            return true;
        }
        for (int j=0; j<bucket.size(); ++j){
            if (bucket[j] + nums[i] > avg){
                continue;
            }else{
                bucket[j] +=nums[i];
                if (bt(nums, bucket, i+1, avg)){
                    // reach last element in nums, find the solution, return true
                    return true;
                }else{
                    // cannot fullfil the bucket
                    bucket[j] -= nums[i];
                }
                if (bucket[j] == 0) {
                    // cannot find element set to fill in this bucket
                    return false;
                }
            }
        }
        return false;
    }
    
};
