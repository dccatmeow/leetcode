/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        if (n<3){
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; ++i){
            int target = 0-nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                if (nums[l]+nums[r] == target){
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    // avoid duplicate
                    while(l<r && nums[l] == nums[l+1]){
                        l++;
                    }
                    while(l<r && nums[r] == nums [r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }else if (nums[l]+nums[r]<target){
                    l++;
                }else if (nums[l]+nums[r]>target){
                    r--;
                }
            }
            // avoid duplicate
            while (i<n-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};
