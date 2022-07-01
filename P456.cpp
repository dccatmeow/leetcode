/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], 
nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.
*/

class Solution {
public:
    // i j k does not have to be consecutive, just i<j<k
    // first need to find the minimum number num_min is i
    // idx is number j in the loop backward
    // number k is in the stack
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len<3) 
            return false;
        // holds min number in nums[0,idx] for each idx
        vector<int> nums_min(len, INT_MAX);
        // Find nums_min
        nums_min[0] = nums[0];
        for(int idx = 1; idx < len; ++idx){
            nums_min[idx] = min(nums_min[idx-1], nums[idx]);
        }
        
        stack<int> myStack;
        // loop from back, idx indicate potential third number
        for (int idx = len-1; idx>=0; --idx){
            // if nums[idx] is the minimum number in nums[0,idx], 
            // there is no solution in [0,idx] considering [0, idx-1] has been checked
            if (nums[idx] > nums_min[idx]){
                // idx is potentially the second value
                // trying to find third number in the stack where it is at least 
                // greater than num_min[idx] the minumum first value
                while(!myStack.empty() && myStack.top() <= nums_min[idx]){
                    // too small as third number
                    myStack.pop();
                }
                if (!myStack.empty() && nums[idx] > myStack.top()){
                    // find the very first bump backward
                    // third value found
                    return true;
                }   
                myStack.push(nums[idx]);
            }
        }
        
        return false;
        
    }
};
