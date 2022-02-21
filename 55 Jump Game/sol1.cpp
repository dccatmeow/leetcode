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
        int i(0);
        int n = nums.size();
        // for example [2 3 1 1 4]
        // first element can jump to 1 position or 2 position
        // find which position goes further
        // 1 have 3
        // 2 have 1
        
        int last_visited(0);
        while(i<n){
            // for case [0]
            if (i+nums[i] >= n-1){
                return true;
            }
            int next = i;
            for (int j=last_visited+1; j<=i+nums[i];++j){
                if (j+nums[j] > next+nums[next]){
                    next = j;
                }
            }
            last_visited = i+nums[i];
            // avoid loop if it stuck at [0] in the middle
            if (i==next){
                return false;
            }else{
                i = next;
            }
        }
        
        return false;
        
    }
};