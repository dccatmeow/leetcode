/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements 
without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (auto i:nums){
            // this is O(logn)
            // use lower_bound to find if i>all element
            // any i<= element should be found
            // any element >= i should be found.
            auto it = lower_bound(res.begin(), res.end(), i);
            if (it == res.end()){
                // i is greater than all element in res
                res.push_back(i);
            }else{
                *it = i;
            }
        }
        return res.size();
    }
};
// time complexity nO(logn)
// space complexity O(n);

//[1,2,7,8,3,4,5,9,0]
//1 -> [1]
//2 -> [1,2]
//7 -> [1,2,7]
//8 -> [1,2,7,8]
//3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence //we need only the last number and 1,2,3 is our new shorter sequence
//4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but //4 has more chances for longer sequence
//5 -> [1,2,3,4,5]
//9 -> [1,2,3,4,5,9]
//0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence
