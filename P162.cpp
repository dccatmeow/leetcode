/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // binary search
        int l(0);
        int r(nums.size()-1);
        while(l<=r){
            if (l==r){
                // this also guard boundary
                return l;
            }
            int mid=l+(r-l)/2;// mid always less than r, no need to worry right boundary
            if (mid == 0){
                // left boundary
                if(nums[0]>nums[1]){
                    // local max
                    return 0;
                }else{
                    l = mid+1;
                }
            }else if (nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                // local max
                return mid;
            }else if (nums[mid]<nums[mid+1]){
                // eg ....1,3....
                l = mid+1;
            }else if (nums[mid]>=nums[mid+1]){
                // mid is not local max 
                // e.g. .... 4, 3(mid),1....
                r = mid-1;
            }
        }
        return l;
    }
};
