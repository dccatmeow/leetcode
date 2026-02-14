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
      // **** dp is the max value it can get with a mask 
      // dp[0] = 0, no element selected
      // dp[1], select nums[0]=1 mask =  0 0 0 1
      vector<int> dp(nMax);
      // starting from 0001 to 1111
      // mask includes all the possible selection till all selected
      for (int mask = 1; mask < nMax; ++mask) {
          //mask represents which NUMBERS are already chosen.
          //__builtin_popcount(x): This function is used to count the number of 1’s(set bits)
          const int selected = __builtin_popcount(mask);
          // fill in from left to right, the slot to be filled is the last one with current mask
          const int slot = (selected + 1) / 2;  // (1, 2) -> 1, (3, 4) -> 2
          for (int i = 0; i < n; ++i){
              if (mask >> i & 1) {
                  // nums[i] is selected
                  // mask right shift i, if i==1 
                  // 1100, i=2, 0011 & 0001 == 0001

                  // flip ith position in mask 1 (1) 0 0
                  // 1 left shift by i, 0100
                  // mask(1100) XOR 0100 = 1000

                  // mask without choosing i last time and choose i this step
                  dp[mask] = max(dp[mask], dp[mask ^ 1 << i] + (slot & nums[i]));
              }
          }
      }

    return dp.back();
  }
};
