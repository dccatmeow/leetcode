/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.
*/

class Solution {
public:
    int calculate(string s) {
        int num(0);
        char op('+');
        int val(0); // accumulated
        // store pair in stack
        // pair<number, operator>
        // when meet with "(", calculate and push everything into stack, with last sign
        //                     reset number to 0
        // when meet with ")", calculate everything and pop top of stack, calculate and continue
        stack<pair<int, char>> stk;
        for(auto c:s){
            if (c == ' '){
                continue;
            }else if (c>='0' && c<='9'){
                // number
                num = 10*num+(c-'0');
            }else if (c =='+' || c == '-'){
                // operator
                // calculate previous operator and add num to val
                if (op == '+'){
                    val = val + num;
                }else{
                    // '-'
                    val = val-num;
                }
                // reset num
                num=0;
                op = c;
            }else if(c == '('){
                // calculate previous operator and add num to val
                stk.push({val, op});
                // reset
                num = 0;
                val=0;
                op = '+';
            }else if (c == ')'){
                // calculate previous operator and add num to val
                if (op == '+'){
                    val = val+num;
                }else{
                    //'-'
                    val = val - num;
                }
                // reset
                num = 0;
                op = '+';
                // pop stack
                if (stk.top().second == '+'){
                    val = stk.top().first+val;
                }else{
                    // '-'
                    val = stk.top().first - val;
                }
                stk.pop();
            }
        }
        // calculate last number
        if (op == '+'){
            val = val+num;
        }else{
            //'-'
            val = val - num;
        }
        return val;
    }
};
