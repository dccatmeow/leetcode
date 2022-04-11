/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        if (n<4){
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int sumTwo=target-nums[i]-nums[j];
                int l = j+1;
                int r = n-1;
                while(l<r){
                    int tmp = nums[l]+nums[r];
                    if (tmp == sumTwo){
                        res.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]){
                            ++l;
                        }
                        while(l<r && nums[r] == nums[r-1]){
                            r--;
                        }
                        l++;
                        r--;
                    }else if (tmp < sumTwo){
                        l++;
                    }else if (tmp > sumTwo){
                        r--;
                    }
                }
                while(j<n-1 && nums[j] == nums[j+1]){
                    ++j;
                }
            }
            while(i<n-1 && nums[i] == nums[i+1]){
                    ++i;
            }
        }
        return res;
    }
};
