class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int p=-1, q=0;
        // Find the largest index i such that nums[i] < nums[i + 1]. 
        for (int i=n-2; i>=0; i--){
            if (nums[i]<nums[i+1]){
                p=i;
                break;
            }
        }
        if (p==-1){
            // If no such p exists, just reverse nums and done.
            // 4321 -> 1234
            reverse(nums.begin(), nums.end());
        } else{
            // Find the largest index q > p such that nums[q] > nums[p]
            for (int i=n-1; i>p; --i){
                if (nums[i]>nums[p]){
                    q = i;
                    break;
                }
            }
            swap(nums[p], nums[q]);
            // Reverse the sub-array nums[p + 1:].
            reverse(nums.begin()+p+1, nums.end());
        }
    }
};
