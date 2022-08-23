/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt 
(in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l(0);
        int r(0);
        // find the max to use as left boundary
        // sum of the weights as right boundary
        for (auto i:weights){
            if (i>l){
                l = i;
            }
            r = r+i;
        }
        while(l<=r){
            int m = l+ (r-l)/2;
            // calculate days with capacity m
            int tmp(0);
            int c(1);// count of days
            for (auto i:weights){
                tmp = tmp+i;
                if(tmp>m){
                    tmp = i;
                    c++;
                }
            }
            if (c>days){
                // need more capacity
                l = m+1;
            }else if (c<days){
                r = m-1;
            }else if (c==days){
                // try to minimize capacity
                r = m-1;
            }
        }
        return l;
    }
};
