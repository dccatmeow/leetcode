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
        int n = s.size();
        if (n==0) return 0;
        if (n==1) return 1;
        int res=0;
        unordered_map<char,int> m;
        int l(0);
        for (int i=0;i<n;++i){
            if (m.find(s[i])!=m.end() && m[s[i]]!=-1){
                res = max (res, i - l);
                // invalid from l to tmp-1
                // l....m[s[i]]....i
                int tmp = m[s[i]];
                for (int j=l;j<tmp;++j){
                    m[s[j]] = -1;
                }
                l = tmp+1;
            }
            m[s[i]] = i;
        }
        if (l!=n-1){
            res = max(res, n-l);
        }
        return res;
    }
};
