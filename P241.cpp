/*
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> res;
        char tmp;
        for(int i=0; i<n; ++i){
            // 1 + 1
            // 0 1 2
            // i=1 expression[1] = '+'
            tmp = expression[i];
            if (tmp == '+' || tmp == '-' || tmp == '*'){
                // recrusion call left and right part
                vector<int> left = diffWaysToCompute( expression.substr(0,i) );
                vector<int> right = diffWaysToCompute( expression.substr(i+1) );
                for (auto p:left){
                    for (auto q:right){
                        if (expression[i] == '+'){    
                            res.push_back(p+q);
                        }else if (expression[i] == '-'){
                            res.push_back(p-q);
                        }else if (expression[i] == '*'){
                            res.push_back(p*q);
                        }
                    }
                }
            }
        }
        
        if (res.empty()){
            // expression is a number
            res.push_back(stoi(expression));
        }
        
        return res;
    }
};
