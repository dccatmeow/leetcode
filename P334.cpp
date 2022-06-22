/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.
*/

class Solution {
public:
    
    bool increasingTriplet(vector<int>& nums) {
        // store a pair of two numbers val.first<val.second
        // this pair is the best suitable to find the third element in triplet
        // v1 < v2 < num
        int v1 = INT_MAX;
        int v2 = INT_MAX;
        // keep track of smallest value
        // e.g. 8, 9, 1, ...
        // it could be 8, 9, 1, 10
        // or it could be 8, 9, 1, 2, 3
        // we need to store 1 
        int s = INT_MAX;
        
        for (auto const& num : nums) {
            if (num > v2) {
                // v1, v2, num is a triplet
                return true;
            } else if (num > s && num<v2){
                // num is between s and v2
                // update v1 to s
                // update v2 to num
                // s, num is the smallest pair we can find
                v1 = s;
                v2 = num;
            }else if (num < s){
                s = num;
            }
        }
        return false;
    }
};
