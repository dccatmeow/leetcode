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
        // left and right count for brackets
        int l(0), r(0), res(0);
        for (auto c:s){
            if (c=='('){
                // check balance for previous section
                if (r == 2*l){
                    r=0;
                    l=0;
                }else{
                    if (r%2 == 1){
                        // r is odd number
                        // compensate r to even number
                        r++;
                        res++;
                    }
                    // it is OK for l>r/2
                    if (l>r/2){
                        // remove paired ())
                        l = l-r/2;
                        r = 0;
                    }else if (l<r/2){
                        // compensate l and add to res
                        res = res+r/2-l;
                        l=0;
                        r=0;
                    }
                }
                l++;
            }else if (c==')'){
                r++;
            }
        }
        // compensate unbalanced l and r
        if (r%2 == 1){
            // odd number
            r++;
            res++;
        }
        if (r > 2*l){
            res = res+ r/2 - l;
        }else if (r<2*l){
            res = res+ 2*l-r;
        }
        return res;
    }
};
