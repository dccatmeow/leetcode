/*
You are given an integer array nums of length n and an integer numSlots such that 2 * numSlots >= n. 
There are numSlots slots numbered from 1 to numSlots.

You have to place all n integers into the slots such that each slot contains at most two numbers. 
The AND sum of a given placement is the sum of the bitwise AND of every number with its respective slot number.

For example, the AND sum of placing the numbers [1, 3] into slot 1 and [4, 6] into slot 2 is equal to 
(1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4.
Return the maximum possible AND sum of nums given numSlots slots.

Example 1:

Input: nums = [1,2,3,4,5,6], numSlots = 3
Output: 9
Explanation: One possible placement is [1, 4] into slot 1, [2, 6] into slot 2, and [3, 5] into slot 3. 
This gives the maximum AND sum of (1 AND 1) + (4 AND 1) + (2 AND 2) + (6 AND 2) + (3 AND 3) + (5 AND 3) = 1 + 0 + 2 + 2 + 3 + 1 = 9.
*/
class Solution {
public:
 int maximumANDSum(vector<int>& nums, int numSlots) {
     // each slot has 2 numbers
     const int n = 2 * numSlots;
     // expand nums to n, the rest are 0
     nums.resize(n);
     // if n=4, 2 slots, nums = [1,2,3], add one 0
     //             nums = [1,2,3,0]
     // max bit mask looks like 1 1 1 1, 1 means chosen
     // less than 10000, 1 left shift by n
     const int nMax = 1 << n;
     // dp[x] is the max value we get if assigning the numbers marked
     // in the x to be assigned to the first few slots. For example, 
     // dp[001011] means get 1st, 2nd, and 4th number and assign them 
     // to the two positions in slot 1 and the first position in slot2,
     // the max value we can get is dp[001011]. Note it is not global 
     // max of assigning these numbers to any slots.
     vector<int> dp(nMax);
     // starting from 0001 to 1111…
     for (int mask = 1; mask < nMax; ++mask) {
         //mask represents NUMBERS are already chosen and placed.
         //__builtin_popcount(x): This function is used to count the number of 1’s(set bits)
         const int selected = __builtin_popcount(mask);
         // say we are trying to find dp[001011] now, we are trying to fill
         // the a number (from number of 1s we have, we are trying to fill 
   // a third number), it can be the first number which corresponds to
         // 00101[1], or the second number which is 0010[1]1, or the 4th 
   // number which is 00[1]011. The strategy is to loop over each bit
   // in the mask, if it is 1, then mask it out and update dp[001011]
         const int slot = (selected + 1) / 2;  // (1, 2) -> 1, (3, 4) -> 2
         for (int i = 0; i < n; ++i){
             if (mask >> i & 1) {
			// if bit is 1
		     // mask out current 1 bit to get previous mask
		     int previous_mask = mask ^ 1 << i;
                 // mask without choosing i last time and choose i this step
                 dp[mask] = max(dp[mask], dp[previous_mask] + (slot & nums[i]));
             }
         }
     }
   return dp.back();
 }
};
