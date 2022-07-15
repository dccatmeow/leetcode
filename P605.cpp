/*You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, 
return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
  */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int count = 0;
        if (sz==1){
            // only one pot, need it empty to be able to plant
            if (flowerbed[0] == 0){
                count++;
            }
            return count>=n;
        }
        if (sz == 2){
            // 2 pots need to have both empty to be able to plant
            if (flowerbed[0] == 0 && flowerbed[1] == 0){
                count++;
            }
            return count>=n;
        }
        // sz>=3 cases
        // right boundary add a 0 to cover cases like 1,0,0
        flowerbed.push_back(0);
        int i=0;
        // left boundary use variable to track left part
        int left = 0;
        while(i<sz){
            // adjacent three pots are empty, we can plant
            if (left == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                count++;
                left = flowerbed[i];
                i = i+2;
            }else{
                left = flowerbed[i];
                ++i;
            }
        }
        return count>=n;
        // consider left boundary cases
        
    }
};
