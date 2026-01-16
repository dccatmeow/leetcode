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
        unordered_map<int,int> m;
        int start(0),res(0);
        for (int i=0;i<s.size();++i){
            char tmp = s[i];
            if (m.find(tmp)!=m.end()){
                // find duplicate and erase from m
                if (start==0){
                    res = max(res, i);
                }else{
                    res = max(res, i-start);
                }
                for (int j=start; j<m[tmp];j++){
                    m.erase(s[j]);
                }
                start = m[tmp]+1;
            }
            m[tmp]=i;
        }
        // count last case in m
        int last = s.size()-start;
        res = max(res, last);
        return res;   
    }
};
