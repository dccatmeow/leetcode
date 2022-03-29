/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
*/
class Solution {
public:
    int calculate(string s) {
        s.push_back('+');
        stack<pair<char, int>> stk;
        int num(0);
        int val(0);
        char op('+');
        for (auto c:s){
            if (c ==' '){
                continue;
            }else if (c >= '0' && c<='9'){
                // number
                num = num*10 + (c-'0');
            }else if (c == '+' || c == '-'){
                // calculate previous op and num to val
                if(op == '+'){
                    val = val +num;
                }else if (op=='-'){
                    val = val - num;
                }else if (op == '*'){
                    auto [tmpc,tmpi]=stk.top();
                    stk.pop();
                    tmpi = tmpi*num;
                    stk.push({tmpc, tmpi});
                }else if (op == '/'){
                    auto [tmpc,tmpi]=stk.top();
                    stk.pop();
                    tmpi = tmpi/num;
                    stk.push({tmpc, tmpi});
                }
                // reset
                num=0;
                op = c;
            }else if (c=='*' || c=='/'){
                // push into stk
                // 1+3*2
                // op='+', num='3'
                if (op == '+'|| op=='-'){
                    stk.push({op, num});
                }else if (op =='*'){
                    // 1*3*2, +1 is already in stack, op is first *, c is second *
                    auto [tmpc,tmpi]=stk.top();
                    stk.pop();
                    tmpi = tmpi*num;
                    stk.push({tmpc, tmpi});
                }else if (op == '/'){
                    auto [tmpc,tmpi]=stk.top();
                    stk.pop();
                    tmpi = tmpi/num;
                    stk.push({tmpc, tmpi});
                }
                // reset
                num=0;
                op = c;
            }
        }
        // at the end of for loop is a number
        
        while (!stk.empty()){
            auto [tmpc,tmpi]=stk.top();
            stk.pop();
            if (tmpc == '+'){
                val = val + tmpi;
            }else{
                //'-'
                val = val-tmpi;
            }
        }
        return val;
    }
};
