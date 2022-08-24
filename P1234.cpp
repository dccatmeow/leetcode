/*
You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.

A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. 
If s is already balanced, return 0.

Example 1:

Input: s = "QWER"
Output: 0
*/

class Solution {
public:
    int balancedString(string s) {
        unordered_map<char,int> m;
        for (auto e:s){
            m[e]++;
        }
        int avg = s.size()/4;
        if (m['Q']==avg && m['W'] == avg && m['E'] == avg && m['R'] == avg){
          return 0;  
        } 
        // Use sliding window to make the rest of elements all less than avg
        // part1  window part2
        // part1+part2 has all the elements less than avg
        int l(0);
        int res(s.size());
        for (int r=0; r<s.size(); ++r){
            // as r move to the right, reduce count
            m[s[r]]--;
            // move left boundary
            while(m['Q']<=avg && m['W'] <= avg && m['E'] <= avg && m['R'] <= avg){
                res = min(res, r-l+1);
                m[s[l]]++;
                l++;
            }
        }
        return res;
        
    }
};
