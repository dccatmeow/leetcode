/*
290. Word Pattern
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int j=0;
        unordered_map<char, string> m;
        unordered_map<string, char> strm;
        int i=s.find(' ',0);
        string str = s.substr(0,i);
        m[pattern[j]] = str;
        strm[str] = pattern[j];
        j++;
        while(i<s.size()){
            int prev = i;
            i = s.find(' ', i+1);
            if (i==-1){
                i = s.size();
            }
            string act = s.substr(prev+1, i-(prev+1));
            auto m_iter = m.find(pattern[j]);
            auto strm_iter = strm.find(act);
            if (m_iter==m.end() && strm_iter==strm.end()){
                // not found
                m[pattern[j]] = act;
                strm[act] = pattern[j];
            }else if (m_iter!=m.end() && m[pattern[j]] == act
            && strm_iter !=strm.end() && strm[act] == pattern[j]){
                // found
                ++j;
                continue;
            }else{
                return false;
            }
            j++;
        }
        if (j!=pattern.size()){
            return false;
        }
        return true;
    }
};
