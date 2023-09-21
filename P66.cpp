/*
66. Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i=digits.size()-1; i>=0; --i){
            if(digits[i]==9){
                digits[i] = 0;
            }else{
                digits[i] +=1;
                return digits;
            }
        }
        // need to add 1 in front
        vector<int> res(digits.size()+1,0);
        res[0] = 1;
        for (int i=0;i<digits.size();++i){
            res[i+1] = digits[i];
        }
        
        return res;
    }
};
