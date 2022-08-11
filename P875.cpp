/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxV = 0;
        for (auto i:piles){
            if (maxV<i){
                maxV = i;
            }
        }
        double sumV=0;
        int left = 1;
        int right = maxV;
        int mid = 0;
        // get left boundary
        while(left<=right){
            mid = (left+right)/2;
            for (auto i:piles){
                sumV+=i/mid;
                if (i%mid!=0){
                    sumV++;
                }
            }
            if (sumV>h){
                left = mid+1;
            }else if(sumV<=h){
                right = mid-1;
            }
            // clear value
            sumV=0;
        }
        return left;
    }
};
