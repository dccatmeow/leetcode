/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int res2 = (0+n)*(n+1)/2;
        vector<bool> visited(n, false);
        int res1;
        for (auto i:nums){
            if (visited[i]){
                // find the duplicated number
                res1 = i;
            }else{
                res2=res2-i;
                visited[i]=true;
            }
        }
        return vector<int>{res1, res2};
    }
};
