/*793. Preimage Size of Factorial Zeroes Function

Let f(x) be the number of zeroes at the end of x!. Recall that x! = 1 * 2 * 3 * ... * x and by convention, 0! = 1.

For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has two zeroes at the end.
Given an integer k, return the number of non-negative integers x have the property that f(x) = k.

 

Example 1:

Input: k = 0
Output: 5
Explanation: 0!, 1!, 2!, 3!, and 4! end with k = 0 zeroes.
Example 2:

Input: k = 5
Output: 0
Explanation: There is no x such that x! ends in k = 5 zeroes.
*/

class Solution {
public:
    int preimageSizeFZF(int k) {
        // find left bound
        long l=0;
        long r=LONG_MAX;
        while(l<=r){
            long mid = l+(r-l)/2;
            long tmp = zeros(mid);
            if (tmp<k){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        long left = l;
        // find right bound
        l=0;
        r = LONG_MAX;
        while(l<=r){
            long mid = l+(r-l)/2;
            long tmp = zeros(mid);
            if (tmp<=k){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return r-left+1;
    }
    
    long zeros(long n){
        long tmp(n);
        long res(0);
        while(tmp!=0){
            tmp = tmp/5;
            res+=tmp;
        }
        return res;
    }
}; 
