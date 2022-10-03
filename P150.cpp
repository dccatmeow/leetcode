/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, 
and there will not be any division by zero operation.

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStk;
        for (auto s:tokens){
            // if s is operator
            // pop two numbers and calculate
            // push one number back in
            if (s == "+"){
                int i = numStk.top();
                numStk.pop();
                i += numStk.top();
                numStk.pop();
                numStk.push(i);
            } else if (s == "-"){
                int i=numStk.top();
                numStk.pop();
                i = numStk.top()-i;
                numStk.pop();
                numStk.push(i);
            } else if (s == "*"){
                int i=numStk.top();
                numStk.pop();
                i = numStk.top()*i;
                numStk.pop();
                numStk.push(i);
            }else if (s== "/"){
                int i=numStk.top();
                numStk.pop();
                i = numStk.top()/i;
                numStk.pop();
                numStk.push(i);
            }else{
                // negative number set flag
                int i=0;
                bool nflag(false);
                for (auto c:s){
                    if (c == '-'){
                        nflag = true;
                    }else{
                        i = (c-'0')+i*10;
                    }
                }
                if (nflag){
                    i = -i;
                }
                numStk.push(i);
            }
        }
        return numStk.top();
    }
};
