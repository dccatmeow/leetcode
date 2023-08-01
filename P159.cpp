/*
159. Longest Substring with At Most Two Distinct Characters
Given a string s, return the length of the longest 
substring
 that contains at most two distinct characters.

Example 1:

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l(0), cnt(0);
        int res(0);
        int n=s.size();
        unordered_map<char,int> m;
        for (int r=0;r<n;++r){
            if (m.find(s[r]) == m.end()){
                if (cnt == 2){
                    res = max(res, r-l);
                    // shift l
                    while(cnt == 2){
                        m[s[l]]--;
                        if (m[s[l]]==0){
                            m.erase(s[l]);
                            cnt--;
                        }
                        l++;
                    }
                }
                // add r
                cnt++;
                m[s[r]]++;
            }else{
                m[s[r]]++;
            }
        }
        res = max(res, n-l);
        return res;
    }
};
