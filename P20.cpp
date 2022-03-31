/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char e;
        for (auto c:s){
            if (c == '(' || c=='[' || c=='{'){
                stk.push(c);
            }else{
                if (stk.empty()){
                    return false;
                }
                e = stk.top();
                stk.pop();
                if (!( (e == '(' && c==')') || (e == '[' && c == ']') || (e == '{' && c=='}') )){
                    return false;
                }
            }
        }
        if (!stk.empty()){
            return false;
        }
        return true;
    }
};
