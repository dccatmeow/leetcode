/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // [1, 3, -1, -3, -4], k=3
        // store index of nums in dq
        // pop any value nums[dq.back()] that is smaller than nums[i] from back of dq
        // as these number is no longer needed
        // [0]
        // [1]
        // [1,2] // push back nums[dq.front()] to res, because 3 element is there
        // [1,2,3] // push back nums[dq.front()] to res
        // i=4, dq=[1,2,3]->[2,3,4]
        // pop front as new element -4's sliding window does not include 3, i-dq.front()=4-1=3
        // push back nums[dq.front()] to res
        // res = 
        deque<int> dq;
        vector<int> res;
        int l = nums.size();
        for (int i=0;i<l;++i){
            if (!dq.empty() && (i-dq.front())==k){
                // the window size is k 
                // when i-dq.front() == k, it means the sliding window left side should move
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                // dq.back is less than the value nums[i] will be pop
                dq.pop_back();
            }
            dq.push_back(i);
            // save in res
            if (i>=k-1){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// time complexity linear O(n)
