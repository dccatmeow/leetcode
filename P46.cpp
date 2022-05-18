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
    vector<vector<int>> permute(vector<int>& nums) {
        // back track
        vector<int> tmp;
        permuteV(nums, tmp);
        return res;
    }
    
    void permuteV(vector<int>& nums, vector<int>& tmp){
        if (tmp.size() == nums.size()){
            res.push_back(tmp);
            return;
        }
        for (auto i:nums){
            auto it = find(tmp.begin(), tmp.end(), i);
            if (it != tmp.end()){
                continue;
            }else{
                tmp.push_back(i);
                permuteV(nums, tmp);
                tmp.pop_back();
            }
        }
    }
private:
    vector<vector<int>> res;
};
// time complexity O(n^2)
// space complexity O(n)
