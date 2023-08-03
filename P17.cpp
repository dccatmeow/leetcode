/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

class Solution {
public:
    vector<string> m{"abc", "def", "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"};
    vector<int> pos;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        for (auto c:digits){
            pos.push_back(c-'0'-2);
        }
        if (digits.empty()){
            return res;
        }
        bt("");
        return res;
    }
    void bt(string s){
        int n = s.size(); // the next position
        int j = pos[n]; // location in m
        for (int i=0; i<m[j].size();++i){
            s = s+m[j][i];
            if (s.size() == pos.size()){
                res.push_back(s);
            }else{
                bt(s);
            }
            s.erase(n,1);
        }
    }
};
