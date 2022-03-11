/*
172. Factorial Trailing Zeroes
Medium

1896

1637

Add to List

Share
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        // 2*5 = 10 has one 0
        // find all the number end with 0 or 5 gives the first set
        // 25, 50 can have 2 5, so these are second set
        // 125 has 3 5, so these are third set
        int tmp(n);
        int res(0);
        while(tmp!=0){
            tmp = tmp/5;
            res = res+tmp;
        }
        return res;
    }
};
