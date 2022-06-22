/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
*/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        presum.resize(nums.size());
        presum[0] = nums[0];
        for (int i=1; i<nums.size();++i){
            presum[i] = presum[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0){
            return presum[right];
        }else{
            return presum[right]-presum[left-1];
        }
    }
private:
    vector<int> presum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
