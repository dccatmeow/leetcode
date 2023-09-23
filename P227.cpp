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
        s = s + '+';
        int val(0);
        char op = '+';
        int num(0);
        for (int i=0; i<s.size();++i){
            char c = s[i];
            if (c==' '){
                continue;
            }else if (c>='0'&&c<='9'){
                num = num*10+(c-'0');
            }else if (c=='+'||c=='-'){
                if (op=='+'){
                    val +=num;
                }else{
                    val -= num;
                }
                // clear op and num
                op=c;
                num=0;
            }else{
                // * or /
                char op2 = c;
                double num2(0);
                i++;
                while(s[i] == ' '){
                    i++;
                }
                while(s[i]>='0'&&s[i]<='9'){
                    num2 =num2*10+(s[i]-'0');
                    ++i;
                }
                if (op2 == '*'){
                    num = num * num2;
                }else{
                    num = (num/num2);
                }
                --i;
            }
        }
        return val;
    }
};
