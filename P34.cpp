/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()){
            return vector<int>(2,-1);
        }
        int n = nums.size();
        int l(0), r(n-1);
        vector<int> res;
        while(l<=r){
            // find left boundary
            int m = l+(r-l)/2;
            if (nums[m]>target){
                r = m-1;
            }else if (nums[m]<target){
                l = m+1;
            }else if (nums[m] == target){
                r = m-1;
            }
        }
        if (l<0 || l>=n || nums[l]!=target){
            // not found
            return vector<int>(2, -1);
        }else{
            res.push_back(l);
        }
        r = n-1;
        while(l<=r){
            // find right boundary
            int m = l+(r-l)/2;
            if (nums[m]>target){
                r = m-1;
            }else if (nums[m]<target){
                l = m+1;
            }else if (nums[m] == target){
                l = m+1;
            }
        }
        res.push_back(r);
        return res;
    }
};
