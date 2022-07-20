/*
You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).
*/
class Solution {
public:
    bool isPossible(vector<int>& nums) { 
        // add a number to make last element in nums can be checked by all the logic
        nums.push_back(1002);
        // keep track count of each position
        // pos[0] is the count of element at first position
        // e.g. [1,1,2,3]
        // 1: pos = [0,0,0], count++
        // 1: pos = [2,0,0]
        // 2: pos = [1,1,0]
        // [1], [1,2]
        // pos[0] = 1 for [1]
        // pos[1] = 1 for [1,2]
        vector<int> pos(3,0);
        // first move pos[0], then pos[1], if still has extra start a new one
        // because after satisfying the length >=3 restriction
        // extend existing sequence is always safer than restart a new one
        int current = nums[0];
        int count(0); // for initial condition
        for (auto i:nums){
            if (i == current){
                // calculate identical numbers i
                count++;
            }else{
                if (pos[0]+pos[1]>count){
                    // i cannot fulfill pos1 and pos2
                    // e.g. [1,1,2,3]
                    // 3: pos = [1,1,0], count = 1
                    return false;
                }
                // calculate next by shift pos
                // pos[0]   pos[1]   pos[2]
                //          next[0]  next[1] next[2]
                vector<int> next(3,0);
                next[1] = pos[0];
                next[2] = pos[1];
                // pos[2] already satisfy subsequence, extend it
                if (pos[2] >= count-pos[0]-pos[1]){
                    // cannot or barely extend all of pos[2]
                    // add up the left in count for next[2]
                    next[2] += count-pos[0]-pos[1];
                }else{
                    // count can fill pos[2] and more
                    next[2] += pos[2];
                    // place rest of count in next[0]
                    next[0] = count - next[1] - next[2];
                }
                pos = move(next);
                
                // after clear count check if not consecutive
                if (i!=current+1){
                    if(pos[0]!=0 || pos[1]!=0){
                        // still has [1] or [1,2] left and not consecutive 
                        return false;
                    }else{
                        // reset every element in pos
                        std::fill(pos.begin(), pos.begin()+3, 0);
                    }
                }
                // reset count
                count = 1;
                current = i;
            }
        }
        return true;
    }
};
