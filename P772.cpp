/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1+1"
Output: 2
*/

class Solution {
public:
    int calculate(string s) {
        s.push_back('+');
        stack<tuple<int, char, int, char>> stk;
        int num(0);
        int val(0); // accumulate value
        char op('+');
        int i(0);
        while(i<s.size()){
            char c = s[i];
            ++i;
            if (c == ' '){
                continue;
            }else if (c>='0' && c <= '9'){
                num = num*10+(c-'0');
            }else if (c == '+' || c == '-'){
                if (op == '+'){
                    val = val + num;
                }else if (op == '-'){
                    val = val - num;
                }
                num = 0;
                op = c;
            }else if (c == '*' || c == '/'){
                // calculate all the * or / until operator no longer is * or /
                // op is either '+' or '-' because * and / are consumed here
                // val + num * num1 ...
                int num1(0);
                if (s[i] == '('){
                    // val + num * (...
                    // push into stk
                    stk.push(tuple(val, op, num, c));
                    // reset
                    num = 0;
                    val = 0;
                    op = '+';
                    ++i;
                    continue;
                }
                while(s[i]>='0' && s[i] <= '9'){
                    // find num1
                    num1 = num1*10 +(s[i]-'0');
                    ++i;
                }
                if (c == '*'){
                    num = num*num1;
                }else if (c == '/'){
                    num = num/num1;
                }
            }else if (c == '('){
                // push to stk
                // val + 1*(...
                stk.push(tuple(val, op, 1, '*'));
                // reset
                num = 0;
                val = 0;
                op = '+';
            }else if (c == ')'){
                // val + num)
                if (op == '+'){
                    val = val + num;
                }else if (op == '-'){
                    val = val - num;
                }
                // pop from stk
                // sVal + sNum * (val)
                auto [sVal, op1, sNum, op2] = stk.top();
                stk.pop();
                if (op2 == '*'){
                    sNum = sNum * val;
                }else if (op2 =='/'){
                    sNum = sNum/val;
                }
                // sVal op1(+) sNum
                val = sVal;
                op = op1;
                num = sNum;
            }
        }
        
        return val;
    }
};
