/*55. Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element 
in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if (n<=1){
            return true;
        }
        // the range first step can reach
        int l(0);
        int r(nums[0]);
        while(l<r){
            // current step can reach [l,r]
            if (r>=n-1){
                return true;
            }
            int maxDist(0);
            for (int k=l; k<=r; ++k){
                maxDist = max(maxDist, k+nums[k]);
            }
            // set step for next round
            l = r;
            r = maxDist;
        }
        return false;
    }
};
