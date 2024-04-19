/*
2781. Length of the Longest Valid Substring
You are given a string word and an array of strings forbidden.

A string is called valid if none of its substrings are present in forbidden.

Return the length of the longest valid substring of the string word.

A substring is a contiguous sequence of characters in a string, possibly empty.

 

Example 1:

Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
Output: 4
Explanation: There are 11 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", "ab", "abc" and "aabc". The length of the longest valid substring is 4. 
It can be shown that all other substrings contain either "aaa" or "cb" as a substring. 

*/

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int len = 0; // max forbidden word length
        unordered_set<string> all; // hash table for forbidden words
        for (const string &s : forbidden) {
            all.insert(s);
            len = max(len, (int) s.length());
        }
        const int n = word.size();
        int res = 0;
        int right = n; // right boundary
        // find longest string without forbidden word backward
        for (int i = n - 1; i >= 0; --i) {
            if (right<=res){
                // too short than res
                break;
            }
            int now = 0;
            string temp;
            // from i to i+len-1 to see if there is any substring find in all which violate the rule
            for (int j = i; j < right && j - i < len; ++j) {
                temp.push_back(word[j]);
                if (all.find(temp)!=all.end()) {
                    // find a matched in all
                    right = j; // right boundary of string starting from i
                    break;
                }
            }
            res = max(res, right - i);
        }
        return res;
        
    }
};
