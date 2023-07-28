/*
1249. Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l(0);
        int n=s.size();
        vector<int> tmp;
        for(int i=0; i<n;++i){
            if (s[i]=='('){
                l++;
            }else if (s[i]==')'){
                if (l>0){
                    l--;
                }else{
                    tmp.push_back(i);
                }
            }
        }
        // remove extra )
        for (int i=tmp.size()-1; i>=0;--i){
            s.erase(tmp[i],1);
        }
        // remove extra (
        int i=s.size()-1;
        while (l>0 && i>=0){
            if (s[i]=='('){
                s.erase(i,1);
                l--;
            }
            i--;
        }
        return s;
    }
};
