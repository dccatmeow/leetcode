/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        // calculate each digit by digit and move it to the correct position add up to res
        int size1 = num1.size();
        int size2 = num2.size();
        vector<int> res(size1+size2,0);
        int pos, sum, carry;
        for (int i=0; i<size1; ++i){
            for ( int j=0; j<size2; ++j){
                //int pos = size1+size2-1 - (size1-1-i) - (size2-1-j);
                pos = i+j+1;
                sum = res[pos]+(num1[i]-'0')*(num2[j]-'0');
                carry = sum/10;
                res[pos] = sum%10;
                pos--;
                // resolve carry
                while(carry){
                    sum = res[pos]+carry;
                    carry = sum/10;
                    res[pos] = sum%10;
                    pos--;
                }
            }
        }
        
        // convert res to string       
        string s;
        bool flag=false;
        for (auto i:res){
            if (flag){
                s.push_back(i+'0');
                continue;
            }
            if (i!=0){
                flag=true;
                s.push_back(i+'0');
            }
        }
        if (s.empty()){
            return "0";
        }
        return s;
    }
};
