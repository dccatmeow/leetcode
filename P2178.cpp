/*
You are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.

For example, given finalSum = 12, the following splits are valid (unique positive even integers summing up to finalSum):
(12), (2 + 10), (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the maximum number of integers. 
Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.
Return a list of integers that represent a valid split containing a maximum number of integers. 
If no valid split exists for finalSum, return an empty list. You may return the integers in any order.

Example 1:

Input: finalSum = 12
Output: [2,4,6]
*/
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        // odd number return
        if (finalSum%2){
            return res;
        }
        long long tmp(0);
        for (long long i=2; i<=finalSum ; i=i+2){
            // add i to tmp
            tmp += i;
            // check the remainder
            if (finalSum-tmp <= i){
                // next number will be duplicated
                res.push_back(i+finalSum-tmp);
                break;
            }else{
                res.push_back(i);
            }
        }
        return res;
    }
};
// time complexity O(sqrt(N)) time.
