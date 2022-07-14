/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left(0), right(0), resL(0), resR(INT_MAX), valid(0);
        unordered_map<char, int> need, window;
        for(auto i:s1){
            need[i]++;
        } 
        // move right side
        while(right!=s2.size()){
            char temp = s2[right];
            if(need.count(temp)){ 
                window[temp]++;
                if (need[temp] == window[temp]){
                    valid++;
                }
            }
            while(valid == need.size()){
                if (right-left == s1.size()-1){
                    return true;
                }
                char temp1 = s2[left];
                left++;
                if (need.count(temp1)){
                    if(need[temp1] == window[temp1]){
                        valid--;
                    }
                    window[temp1]--;
                }
            }
            right++;
         }
        
        return false;
    }
};
// time complexityO(s2.size());
// space complexityO(s1.size())
