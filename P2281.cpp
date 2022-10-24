/*As the ruler of a kingdom, you have an army of wizards at your command.

You are given a 0-indexed integer array strength, where strength[i] denotes the strength of the ith wizard. For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), the total strength is defined as the product of the following two values:

The strength of the weakest wizard in the group.
The total of all the individual strengths of the wizards in the group.
Return the sum of the total strengths of all contiguous groups of wizards. Since the answer may be very large, return it modulo 109 + 7.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: strength = [1,3,1,2]
Output: 44
Explanation: The following are all the contiguous groups of wizards:
- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
- [3] from [1,3,1,2] has a total strength of min([3]) * sum([3]) = 3 * 3 = 9
- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
- [2] from [1,3,1,2] has a total strength of min([2]) * sum([2]) = 2 * 2 = 4
- [1,3] from [1,3,1,2] has a total strength of min([1,3]) * sum([1,3]) = 1 * 4 = 4
- [3,1] from [1,3,1,2] has a total strength of min([3,1]) * sum([3,1]) = 1 * 4 = 4
- [1,2] from [1,3,1,2] has a total strength of min([1,2]) * sum([1,2]) = 1 * 3 = 3
- [1,3,1] from [1,3,1,2] has a total strength of min([1,3,1]) * sum([1,3,1]) = 1 * 5 = 5
- [3,1,2] from [1,3,1,2] has a total strength of min([3,1,2]) * sum([3,1,2]) = 1 * 6 = 6
- [1,3,1,2] from [1,3,1,2] has a total strength of min([1,3,1,2]) * sum([1,3,1,2]) = 1 * 7 = 7
The sum of all the total strengths is 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44.

array:            ... [lm, ... , l2,  l1,  v, r1,  r2, ...  rn] ...
prefix sum  ... plm+1 [plm, ... pl2, pl1, pv, pr1, pr2, ... prn] ...

Say current value is v, within [lm, rn] region, v is the smallest value. 
How do we find the sum of all the subarrays that include value v. We devide 
all subarrays into the following categories:

(0) right boundary is v: [... v]
    inlcude 0 number on the left: pv-pl1
    inlcude 1 number on the left: pv-pl2
    ...
    include m number on the left: pv-plm+1
    sums up to (m+1)*pv - (pl1+pl2+....+plm+1)

(1) right boundary is r1:[... r1]
    (m+1)*pr1 - (pl1+pl2+...+plm+1)

...

(n) right boundary is rn [... rn]
    (m+1)*prn - (pl1+pl2+....+plm+1)

all sums up to:
    (m+1)*(pv+pr1+...+prn) - (n+1)*(pl1+pl2+...+plm+1)

now pv+pr1+...+prn and pl1+pl2+...+plm+1 can be calculated using prefix sum of
the prefix sum array.
*/

class Solution {
public:
    int mod = pow(10,9)+7;
    int totalStrength(vector<int>& strength) {
        // calculate presum
        // construct mono-stack to find smaller element
        int n=strength.size();
        int res(0);
        vector<int> presum(n, 0);
        vector<int> ppresum(n,0);
        presum[0] = strength[0];
        ppresum[0] =presum[0]; // presum of presum
        // store the next smaller element on the left
        // strength 1   3  7
        // nextS    -1  0  1
        vector<int> leftS(n,-1); 
        stack<int> fStk;
        fStk.push(0);
        leftS[0] = -1;
        for (int i=1; i<n; ++i){
            presum[i] = (presum[i-1]+strength[i])%mod;
            ppresum[i] = (ppresum[i-1]+presum[i])%mod;
            while (!fStk.empty() && strength[fStk.top()] > strength[i]){
                // i is smaller than fStk.top()
                fStk.pop();
            }
            if (!fStk.empty()){
                // there is a number on the left of i that is smaller
                leftS[i] = fStk.top();
            } else{
                // itself is the smallest [0,i]
                leftS[i] = -1;
            }
            fStk.push(i);
        }
        // store the next smaller element on the right
        vector<int> rightS(n,n); 
        stack<int> bStk;
        for (int i=n-1; i>=0; --i){
            while (!bStk.empty() && strength[bStk.top()] >= strength[i]){
                // i is smaller or equal to bStk.top()
                bStk.pop();
            }
            if (!bStk.empty()){
                // there is a number on the left of i that is smaller
                rightS[i] = bStk.top();
            } else{
                //i itself is the smallest [i, n-1]
                rightS[i] = n;
            }
            bStk.push(i);

            // calculate range that has i as smallest element
            // (leftS[i], rightS[i])
            // array:            ... [lm, ... , l2,  l1,  v, r1,  r2, ...  rn] ...
            // prefix sum  ... plm+1 [plm, ... pl2, pl1, pv, pr1, pr2, ... prn] ...
            //(m+1)*(pv+pr1+...+prn) - (n+1)*(pl1+pl2+...+plm+1)
            // mm=i-leftS[i]-1;
            // nn=rightS[i]-i-1;
            
            // find all subarray sum in the range of (l,r) including current val
            int l = leftS[i];
            int r = rightS[i];
            long long lsum = (i > 0 ? ppresum[i-1] : 0) - (l > 0 ? ppresum[l-1] : 0);
            long long rsum = ppresum[r-1] - (i > 0 ? ppresum[i-1] : 0);
            res += ((i-l)*rsum - (r-i)*lsum) % mod * strength[i] % mod;
            res %= mod;
        }
        return (res+mod)%mod;
    }
};
