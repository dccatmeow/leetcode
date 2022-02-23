/* 698. Partition to K Equal Sum Subsets
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
 

Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4]. */

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum(0);
        for (auto i:nums){
            sum+=i;
        }
        if (sum%k !=0){
            // cannot devide into k bucket
            return false;
        }
        int sum_b = sum/k;
        sort(nums.begin(), nums.end(), greater());
        vector<int> bucket(k, 0);
        return bt(nums, bucket, 0, sum_b);
    }
    
    bool bt(vector<int>& nums, vector<int>& bucket, int i, int sum){
        if (i == nums.size()){
            return true;
        }
        for (int j=0; j<bucket.size(); ++j){
            if (bucket[j] + nums[i] > sum){
                continue;
            }else{
                bucket[j] +=nums[i];
                if (bt(nums, bucket, i+1, sum)){
                    // reach last element in nums, find the solution, return true
                    return true;
                }else{
                    bucket[j] -= nums[i];
                }
                if (bucket[j] == 0) {
                    break;
                }
            }
        }
        return false;
    }
};
