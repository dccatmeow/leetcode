/*
Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.
 

Example 1:

Input
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
Output
[null, 4, 0, 2]

*/
class Solution {
public:
    Solution(vector<int>& nums) {
        n = nums;
        
    }
    
    int pick(int target) {
        int i=1;
        int res;
        int tmp;
        for (int j=0; j<n.size(); ++j){
            if (n[j]==target){
                tmp = rand()%i;
                if (tmp==0){
                    res = j;
                }
                i++;
            }
        }
        return res;
    }
private:
    vector<int> n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
