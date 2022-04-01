/*
Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
*/

class Solution {
public:
    int minInsertions(string s) {
        int res(0);
        int l(0), r(0);
        int i(0);
        while(i!=s.size()){
            char c = s[i];
            if (c == '('){
                l++;
                i++;
            }else if (c == ')'){
                if (l == 0){
                    if (s[i+1] == ')'){
                        res++;
                        i=i+2;
                    }else{
                        // case ')('
                        res = res+2;
                        i++;
                    }
                }else{
                    // l!=0
                    l--;
                    // previous one cannot be ) without being treated
                    // so previous one has to be (
                    // check next one
                    if (s[i+1] == ')'){
                        // balance ())
                        i = i+2;
                    }else{
                        // s[i+1] == '('
                        i++;
                        // '()('
                        res++;
                    }
                }
            }
        }
        res = res+l*2;
        return res;
    }
};
