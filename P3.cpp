/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> visited;
        int res(0), left(0);
        for (int i=0; i<s.size(); ++i){
            char c = s[i];
            if (visited.count(c) && visited[c]!=-1){
                // visited
                res = max(res, i-left);
                // reset element from left to visited[c]
                for (int j = left; j<visited[c]; ++j){
                    visited[s[j]] = -1;
                }
                left = visited[c]+1;
            }
            // store location of c
            visited[c] = i;
        }
        // at the end check [left, s.size())
        int tmp = s.size()-left;
        res = max(res, tmp);
        return res;
    }
};
