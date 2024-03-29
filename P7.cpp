/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
*/

class Solution {
public:
    int reverse(int x) {
        long long res(0);
        while(x!=0){
            res = res*10 + x%10;
            x = x/10;
        }
        if (res > INT_MAX || res < INT_MIN){
            return 0;
        }
        return res;
    }
};
