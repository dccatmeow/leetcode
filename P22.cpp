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
        num=n*2;
        string tmp;
        bt(tmp);
        return res;
    }
    
    void bt(string& tmp){
        if (tmp.size() == num){
            if (isValid(tmp)){
                res.push_back(tmp);
            }
            return;
        }
        // try 1
        tmp.push_back('(');
        bt(tmp);
        tmp.pop_back();
        // try 2
        tmp.push_back(')');
        bt(tmp);
        tmp.pop_back();
    }
    
    bool isValid(string& s){
        int count(0);
        for (auto e:s){
            if (e == '('){
                count++;
            }else{
                count--;
            }
            if (count<0){
                return false;
            }
        }
        if (count==0){
            return true;
        }else{
            return false;
        }
    }
private:
    vector<string> res;
    int num;
};
