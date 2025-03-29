/*22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        num=n;
        gen("", n, n);
        return res;
    }
    // open is the number of ( to be add
    // close is the number of ) to be add
    void gen(string s, int open, int close){
        if (open==0 && close ==0){
            res.push_back(s);
        } else if (open>close){
            // invalid
        }else if (open==close){
            s = s+'(';
            open--;
            gen(s, open,close);
        }else if (open==0){
            s = s+')';
            close--;
            gen(s,open,close);
        }else{
            // open<close
            gen(s+'(', open-1, close);
            gen(s+')', open, close-1);
        }
    }
private:
    vector<string> res;
    int num;
};
