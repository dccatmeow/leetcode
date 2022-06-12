/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

class Solution {
public:
    int numSquares(int n) {
        // dynamic programming
        // m[n] is the lease number of perfect square number that sum up to n
        vector<int> m(n+1, n);
        m[0] = 0;
        m[1] = 1;
        for (int i=2; i<=n; ++i){
            for(int j=1; j*j<=i;++j){
                m[i] = min(m[i], 1+m[i-j*j]);
            }
        }
        return m[n];
        
    }
};
