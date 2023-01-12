/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
*/

class Solution {
public:
// used a match first element and then a linear scan
// a better solution if string is very long can be rolling hash 

    bool rotateString(string s, string goal) {
        // if length is different, return false
        if (s.size()!=goal.size()){
            return false;
        } 
        int l(0);
        int n = s.size();
        vector<int> pos;
        while(l<n){
            // collect all possible starting position
            auto j = s.find(goal[0], l);
            if (j==string::npos){
                break;
            }else{
                l = int(j)+1;
                pos.push_back(int(j));
            }
        }
        bool res(false);
        for (auto i:pos){
            for (int c=0; c<n;++c){
                if (s[i] != goal[c]){
                    break;
                }
                ++i;
                if (i==n){
                    i=0;
                }
                if (c == n-1){
                    // find a match
                    res = true;
                }
            }
        }
        return res;
    }
};
