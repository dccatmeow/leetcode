/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left(0), right(0), valid(0);
        vector<int> res;
        unordered_map<char, int> need, window;
        // count char in p
        for(auto i:p){
            need[i]++;
        }
        // move right side
        while(right!=s.size()){
            char temp = s[right];
            if (need.count(temp)){
                window[temp]++;
                if(need[temp]==window[temp]){
                    valid++;
                }
            }
            while(valid==need.size()){
                if (right-left+1 == p.size()){
                    res.push_back(left);
                }
                // move left side
                char temp1 = s[left];
                left++;
                if (need.count(temp1)){
                    if(window[temp1] == need[temp1]){
                        valid--;
                    }
                    window[temp1]--;
                }
            }
            
            right++;
        }
        
        return res;
        
    }
};
// time complexity O(s.size())
// space complexity O(1)
