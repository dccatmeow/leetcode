/*
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character 
in this substring is greater than or equal to k.
Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) return 0;
        if (k==1){
            return s.size();
        }
        if (s.size()<k){
            return 0;
        }
        vector<int> count(26,0);
        for (auto elem:s){
            count[elem-'a']++; // count for all letters. It is used to identify if letters has appeared more than k times 
        }
        
        int res=0, len = s.size(), num=0;
        for (int i=0; i<len; ++i){
            if (count[s[i]-'a'] < k){
                // from first met element count less than k to divide the string
                // substring 0 to i-1
                int l = longestSubstring(s.substr(0, i), k);
                // substring i+1, len-1
                int r = longestSubstring(s.substr(i+1, len-i-1), k);
                res = max(res,l);
                res = max(res,r);
                return res;
            }
        }
        // the whole string satisfied all element greater than k
        return len;
    }
};
