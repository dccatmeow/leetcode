/*
The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, 
if two or more integers have the same power value sort them by ascending order.

Return the kth integer in the range [lo, hi] sorted by the power value.

Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x 
is will fit in a 32-bit signed integer.

Example 1:

Input: lo = 12, hi = 15, k = 2
Output: 13
Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
The power of 13 is 9
*/
class Solution {
public:
    using pii=pair<int,int>;
    int getKth(int lo, int hi, int k) {
        vector<pii> v(hi-lo+1, pii());
        // calculate power for each value [lo, hi]
        for (int i=lo; i<=hi; ++i){
            v[i-lo]=pii(power(i),i);
        }
        sort(v.begin(), v.end());
        return v[k-1].second;
    }
    int power(int i){
        if (i==1){
            // boundary condition
            return 0;
        }
        if (i%2==0){
            // even number
            return  power(i/2)+1;
        }else{
            // odd number
            int tmp = 3*i;
            tmp = tmp+1;
            return power(tmp)+1;
        }
        return -1;
    }
private:
    vector<int> mem;
};
