/*
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

class Solution {
public:
    int countPrimes(int n) {
        // 2*2, 2*3, 2*4 these are not prime numbers
        // 3*3, 3*4, ....
        // 4*4, 4*5,....
        // till n
        vector<bool> valid(n+1, true);
        int maxN=sqrt(n);
        for (int i=2; i<=maxN; ++i){
            for (int j=i*i; j<=n; j=j+i){
                valid[j] = false;
            }
        }
        int res(0);
        // 0 is not prime number start from 1
        // 1 is not prime number as prime number can only be divided with 1 and itself, 2 numbers
        for (int i=2; i<n; ++i){
            if (valid[i]){
                res++;
            }
        }
        return res;
    }
};
