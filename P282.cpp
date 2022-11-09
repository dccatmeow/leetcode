/*
Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.

Example 1:

Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
*/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        s = num;
        tar = target;
        bt(0, "", 0, 0);
        return res;
    }

    void bt(int i, string tmp, long val, long prevnum){
        // input argument: 
        // current position in s
        // formed string so far
        // value so far
        // previous num including sign **********
        // current evaluation is val +-* 
        // ... + prevnum = val
        // string has [i, end] left to be explored
        if (i==s.size()){
            if (val == tar){
                res.push_back(tmp);
                return;
            }
        }
        long num(0);
        string str;
        for (int j=i; j<s.size();j++){
            if (s[i]=='0' && j!=i){
                // val +-* 03, not allowed ********
                break;
            }
            num = num*10 + (s[j]-'0');
            str += s[j];
            if (i==0){
                bt(j+1, str, num, num);
            }else{
                // insert '+' '-' '*'
                bt(j+1, tmp+'+'+str, val+num, num);
                bt(j+1, tmp+'-'+str, val-num, -num); // *******
                bt(j+1, tmp+'*'+str, val-prevnum+prevnum*num, prevnum*num);
            }
        }
    }
private:
    vector<string> res;
    string s;
    int tar;
};
