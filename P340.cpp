/*
340. Longest Substring with At Most K Distinct Characters

Given a string s and an integer k, return the length of the longest 
substring
 of s that contains at most k distinct characters.
Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k==0){
            return 0;
        }
        int l(0);
        int n=s.size();
        int cnt(0);
        unordered_map<char,int> m;
        int res(0);
        for (int r=0;r<n;++r){
            // s[r] in m
            if (m.find(s[r])!=m.end()){
                m[s[r]]++;
            }else{
                // new character
                while(cnt==k){
                    // move l
                    m[s[l]]--;
                    if (m[s[l]]==0){
                        m.erase(s[l]);
                        cnt--;
                    }
                    l++;
                }
                m[s[r]]++;
                cnt++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
