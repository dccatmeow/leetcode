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
        // use deque as window
        deque<int> dq;
        vector<int> res;
        for (int i=0; i<nums.size();++i){
            // pop when windows size is larger than k
            if (!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }
            // mono decrease queue, storing index
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                // pop back, until back is greater than nums[i]
                dq.pop_back();
            }
            dq.push_back(i);
            // store max value which is the queue front
            if (i>=k-1){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// time complexity linear O(n)
