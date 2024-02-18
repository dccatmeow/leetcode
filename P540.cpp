class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // only one single number means if single number is on right part of mid
        // left part should be even, 01 23 45 67
        int l(0), r(nums.size()-1);
        while(l<r){
            int mid = l+(r-l)/2;
            // make mid a even number
            if (mid%2 == 1){
                mid--;
            }
            if(nums[mid]!=nums[mid+1]){
                // single number on left part of mid
                r = mid;
            }else{
                // single number on right part of mid
                l = mid+2;
            }
        }
        return nums[l];
    }
};
