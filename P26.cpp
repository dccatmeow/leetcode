/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        // fast pointer and slow pointer
        int slow(0), fast(0);
        while(fast!=n){
            if(nums[slow]==nums[fast]){
                fast++;
            }else{
                slow++;
                nums[slow] = nums[fast];
                fast++;
            }
        }
        return slow+1;
    }
};
