/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) 
deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // get all the positions for each character in s
        vector<vector<int>> pos(26,vector<int>());
        int i=0;
        for (auto c:s){
            pos[c-'a'].push_back(i);
            i++;
        }
        
        int res(0);
        int flag(true);
        // iteratre through all the words
        for (auto word:words){
            // use pre to store matched character's position in s
            int pre(-1);
            flag = true;
            for (auto c:word){
                int idx = c-'a';
                auto it = upper_bound(pos[idx].begin(), pos[idx].end(), pre);
                if (it == pos[idx].end()){
                    // do not find a match for this letter
                    flag = false;
                    break;
                }else{
                    // find a match in s, update pre with position in s
                    pre = *it;
                }
            }
            if (flag){
                res++;
            }
        }
        return res;
    }
};
