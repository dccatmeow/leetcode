/*
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.
Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum(0), maxV(0);
        for(auto i:nums){
            sum+=i;
            if (i>maxV){
                maxV =i;
            }
        }
        int res = sum;
        // sliding window find the valid case for minimum largest subarray sum
        // left is maximum value in nums, right is the total sum
        int left = maxV;
        int right = sum;
        int mid;
        // binary search
        while(left<=right){
            sum =0;
            mid = left+(right-left)/2;
            
            if (isValid(mid, nums, m)){
                // mid is valid try to minimize it
                res = min(res, mid);
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return res;
    }
    
    bool isValid(int maxSum, vector<int>& nums, int expCount){
        int count(0);
        int sum(0);
        for (auto i:nums){
            sum+=i;
            if (sum>maxSum){
                // find the beginning of new subarray, reset sum
                sum = i;
                count++;
            }else if (sum == maxSum){
                sum = 0;
                count++;
            }
        }
        // sum is not 0, need another subarray
        if (sum>0){
            count++;
        }
        return count<=expCount;
    }
};
