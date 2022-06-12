/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l(0), r(0);
        while(r!= nums.size()){
            if (nums[r] == 0){
                r++;
            }else{
                nums[l] = nums[r];
                l++;
                r++;
            }
        }
        for (int i=l; i<nums.size(); i++){
            nums[i] =0;
        }
    }
};
