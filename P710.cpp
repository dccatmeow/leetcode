/*
You are given an integer n and an array of unique integers blacklist. Design an algorithm to pick a random integer in the range [0, n - 1] that is not in blacklist. Any integer that is in the mentioned range and not in blacklist should be equally likely to be returned.

Optimize your algorithm such that it minimizes the number of calls to the built-in random function of your language.

Implement the Solution class:

Solution(int n, int[] blacklist) Initializes the object with the integer n and the blacklisted integers blacklist.
int pick() Returns a random integer in the range [0, n - 1] and not in blacklist.
 

Example 1:

Input
["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
[[7, [2, 3, 5]], [], [], [], [], [], [], []]
Output
[null, 0, 4, 1, 6, 1, 0, 4]

*/

class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        int blkn = blacklist.size();
        validN = n-blkn;
        // mark all the number in black list
        for (auto i:blacklist){
            m[i] = -1;
        }
        // swap blacklist before validN to the end
        // to imagine the case 3 is the only one in blacklist
        // 1 2 3(5) 4 | 5
        // find random number from 1 to 4, when meet with 3 find the corresponding value in the map 5
        int endIdx = n-1;
        for (auto i:blacklist){
            // valid area | invalid area
            // if black list element is >= validN, it is already in the invalid area
            // if block list element is in valid area then swap with valid numbers in the invalid area
            if (i<validN){
                while(m.count(endIdx)){
                    // find number not in the black list
                    endIdx--;
                }
                m[i] = endIdx;
                endIdx--;
                if (endIdx<validN){
                    break;
                }
            }
        }
        
    }
    
    int pick() {
        int tmp = rand()%validN;
        if (m.count(tmp)){
            // black list, pick the value replacing this number
            return m[tmp];
        }else{
            // not in black list
            return tmp;
        }
        
    }
private:
    unordered_map<int, int> m;
    int validN;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
