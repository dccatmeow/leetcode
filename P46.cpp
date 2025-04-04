/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        perm(nums, 0);
        return res;
    }
    void perm(vector<int>& nums, int i){
        if (i==n){
            res.push_back(nums);
            return;
        }
        for (int k=i; k<n;++k){
            swap(nums[i], nums[k]);
            perm(nums, i+1);
            swap(nums[i], nums[k]);
        }
    }
};
// time complexity O(n^2)
// space complexity O(n)
