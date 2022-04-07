/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.
 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        long long res(0);
        int tmp(x);
        if (x<0){
            return false;
        }
        while(tmp!=0){
            res = 10*res+tmp%10;
            tmp = tmp/10;
        }
        return x == int(res);
    }
};
