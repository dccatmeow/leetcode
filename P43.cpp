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
        int m = num1.size();
        int n = num2.size();
        // 0,....m+n stores
        // res[0], 10*res[1],...,10^(m+n-1)*res[m+n-1];
        vector<int> res(m+n, 0);
        // calculate each digit multiplication
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                res[m-1-i+n-1-j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        // calculate res and push carry to upper digit
        int carry(0);
        for(int i=0; i<m+n; ++i){
            res[i] = res[i] + carry;
            carry = res[i]/10;
            res[i] = res[i]%10;
        }
        // resolve when result is 0. At least reserve one digit
        while (res.size()>1 && res.back() == 0){
            res.pop_back();
        }
        string ress{};
        for (int i = res.size()-1; i>=0; --i){
            ress.push_back(res[i]+'0');
        }
        return ress;
    }
};
