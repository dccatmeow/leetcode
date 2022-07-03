/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int l2 = nums2.size();
        vector<int> res;
        unordered_map<int,int> nge;
        // get all the next greater element for nums2
        s.push(nums2[l2-1]);
        nge[nums2[l2-1]] = -1;
        for (auto i=l2-2; i>=0; --i){
            while(!s.empty() && nums2[i]>s.top()){
                s.pop();
            }
            if (s.empty()){
                nge[nums2[i]] = -1;
            }else{
                nge[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        
        for (auto i:nums1){
            res.push_back(nge[i]);
        }
        return res;
    }
};
