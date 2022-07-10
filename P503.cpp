/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int l = nums.size();
        int idx;
        vector<int> res(l, -1);
        s.push(nums[l-1]);
        for (int i=2*l-2; i>=0;--i){
            if (i>=l){
                idx = i-l;
            }else{
                idx = i;
            }
            while (!s.empty() && nums[idx]>=s.top()){
                s.pop();
            }
            if (!s.empty()){
                res[idx] = s.top();
            }
            s.push(nums[idx]);
        }
        return res;
    }
};
