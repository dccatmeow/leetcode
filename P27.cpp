/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast(0), slow(0);
        int n=nums.size();
        while(fast!=n){
            if (nums[fast]==val){
                fast++;
            }else{
                nums[slow]=nums[fast];
                fast++;
                slow++;
            }
        }
        return slow;
    }
};
