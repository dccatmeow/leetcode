/*
Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), 
followed by its count (if that count is more than 1), followed by the second name (in sorted order), 
followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.
Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
*/

class Solution {
public:
    string countOfAtoms(string formula) {
        // use stack to store map when met with '('
        // pop map when met with ')'
        string res;
        map<string, int> m;
        stack<map<string,int>> s;
        int cnt(0);
        string prev;
        // add a dummy element in formula
        formula = formula + 'A';
        for (int i=0; i< formula.size(); ++i){
            char c=formula[i];
            if (c>='0' && c<='9'){
                // number
                cnt = cnt*10+(c-'0');
            }else if (c>='a' && c<='z'){
                prev = prev+c;
            }else if (c>='A' && c<='Z'){
                if (!prev.empty()){
                    // push prev into map m
                    m[prev] += max(cnt,1);
                }
                // update prev to new element
                prev = c;
                cnt = 0;
            }else if (c == '('){
                if (!prev.empty()){
                    // add prev into map m
                    m[prev] += max(cnt,1);
                }
                // update prev to new element
                prev = "";
                cnt = 0;
                // push m into stack
                s.push(std::move(m));
                m.clear();
            }else if (c==')'){
                // e.g. AB)23
                if (!prev.empty()){
                    // add prev into map m
                    m[prev] += max(cnt,1);
                }
                // update prev to new element
                prev = "";
                cnt = 0;
                // calculate 23, i will land in last number
                ++i;
                int tmp(0);
                while(formula[i]>='0'&&formula[i]<='9'){
                    tmp = tmp*10+(formula[i]-'0');
                    ++i;
                }
                --i;
                // for (A)B case
                tmp = max(tmp, 1);
                // update m of "AB" with count tmp
                for (auto e:m){
                    m[e.first] = e.second*tmp;
                }
                // add stack s top prev_m into current map m
                auto prev_m = s.top();
                s.pop();
                for (auto e: prev_m){
                    m[e.first] += e.second;
                }
            }
        }
        // construct string from m
        for (auto p:m){
            if (p.second == 1){
                res = res+p.first;
            }else{
                res = res+p.first+to_string(p.second);
            }
        }
        return res;
    }
};
