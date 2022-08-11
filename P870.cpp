/*
You are given two integer arrays nums1 and nums2 both of the same length. 
The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].

Return any permutation of nums1 that maximizes its advantage with respect to nums2.

Example 1:

Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
Output: [2,11,7,15]
*/

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        // create an index vector idx for nums2
        int len = nums2.size();
        auto idx = std::vector<int>(len, 0);
        for (int i=0; i<len; ++i){
            idx[i] = i;
        }
        // sort idx based on nums2 from largest to smallest
        auto comp = [&nums2](int const& v1, int const& v2){
            return nums2[v1] > nums2[v2];
        };
        std::sort(idx.begin(), idx.end(), comp);
        
        // sort nums1 from largest to smallest
        std::sort(nums1.begin(), nums1.end(), greater<int>());
        int j(0); // index for idx: e.g. idx[j]
        vector<int> res(len,0);
        int pos;
        for (auto i=0; i<len; ++i){
            // nums2[idx[j]] is from largest to smallest
            //nums1[i] is also from largest to smallest
            // find the very first nums2[idx[j]] such that nums1[i] is greater
            while(j<len && nums1[i] <= nums2[idx[j]]){
                ++j;
            }
            if (j<len){
                // nums1[i] > nums2[idx[j]]
                // i is valid, insert number into res
                res[idx[j]] = nums1[i];
                // mark visited position
                idx[j] = -1;
                // move to next position idx[j]
                ++j;
            }else{
                // nums1[i] is invalid for the rest nums2[idx[j]]
                // i is the last position than nums1 is greater than the rest elements in nums2
                pos = i;
                break;
            }
        }
        // fill res with the rest of elements in nums1. e.g.nums1[pos],...,nums[len-1]
        for (auto n:idx){
            if (n!=-1){
                res[n] = nums1[pos];
                pos++;
            }
        }
        return res;
    }
};
