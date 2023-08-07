/*
301. Remove Invalid Parentheses

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]
*/

class Solution {
public:
    unordered_set<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int l(0);
        int r(0);
        int cnt(0);
        for (int i=0; i<s.size();++i){
            char c = s[i];
            if (c=='('){
                l++;
            }else if (c==')'){
                if (l>r){
                    r++;
                }else{
                    // remove ')'
                    cnt++;
                }
            }
        }
        // l-r excess '(' 
        // cnt excess ')'
        bt(s,0, l-r,cnt, 0,0);
        vector<string> resv(res.begin(), res.end());
        return resv;
    }

    void bt(string s, int start, int deltaL, int deltaR, int l, int r){
        if (deltaL<0 || deltaR<0){
            return;
        }
        for(int i=start; i<s.size();++i){
            string str = s;
            if (str[i]=='('){
                // erase this (
                str.erase(i,1);
                bt(str, i, deltaL-1, deltaR, l, r);
                // not erase
                l++;
            }else if (str[i]==')'){
                // erase
                str.erase(i,1);
                bt(str, i, deltaL, deltaR-1, l, r);
                // not erase
                r++;
            }
            if (l<r){
                return;
            }
        }
        if (deltaL==0 && deltaR==0 && l==r){
            res.insert(s);
        }
    }
};
