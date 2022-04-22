/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        // sliding window
        int s_sz = s.size();
        int t_sz = t.size();
        if (s_sz<t_sz){
            return "";
        }
        int left(0);
        int right(0);
        // store char in t to m_t
        // if find string in s that is also in t
        // store it in m_s
        unordered_map<char,int> m_s;
        unordered_map<char, int> m_t;
        for (auto c:t){
            m_t[c]++;
        }
        
        int count(0);
        string res("");
        while(right!=s_sz){
            char rtmp=s[right];
            if (m_t.count(rtmp)){
                m_s[rtmp]++;
                if (m_s[rtmp] == m_t[rtmp]){
                    // first time meet criteria
                    count++;
                }
            }
            if (count==m_t.size()){
                // find a solution
                while(count==m_t.size()){
                    // narrow down left boundary
                    char ltmp = s[left];
                    if (m_t.count(ltmp)){
                        // update map m_s
                        m_s[ltmp]--;
                        if (m_s[ltmp] < m_t[ltmp]){
                            // current left is the boundary, should be included
                            count--;
                        }
                    }
                    left++;
                }
                // [left-1, right]
                int tmplen = right-(left-1)+1;
                if (res.empty() || tmplen<res.size()){
                    res = s.substr(left-1, tmplen);
                }
            }
            right++;
        }
        return res;
    }
};
