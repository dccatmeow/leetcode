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
        unordered_map<char,int> m;
        for (auto c:t){
            m[c]++;
        }
        int l(0);
        int n=s.size();
        std::pair<int,int> res = std::pair<int,int>(0,INT_MAX);
        int cnt(t.size());
        for (int r=0; r<n; ++r){
            if (m.find(s[r])==m.end()){
                continue;
            }else{
                m[s[r]]--;
                if (m[s[r]]>=0){
                    cnt--;
                }
                if (cnt==0){
                    // try to move left side
                    // [l,r]
                    while(l<r && cnt==0){
                        if (m.find(s[l])==m.end()){
                            l++;
                        }else{
                            // s[l] in m
                            if (m[s[l]]==0){
                                // trigger cnt
                                break;
                            }else{
                                // m[s[l]]<0
                                m[s[l]]++;
                                l++;
                            }
                        }
                    }
                    if (r-l<res.second-res.first){
                        res.first = l;
                        res.second = r;
                    }
                    // move left
                    m[s[l]]++;
                    l++;
                    cnt++;
                }
            }
        }
        if (res.second!=INT_MAX){
            return s.substr(res.first, res.second-res.first+1);
        }else{
            return "";
        }
    }
};
