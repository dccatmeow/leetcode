/*8. String to Integer (atoi)
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
  */

Return the integer as the final result.
class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()){
            return 0;
        }
        // leading white space and sign
        bool posFlag = true;
        double res(0);
        int i(0);
        while (s[i]==' '){
            i++;
        }
        if (s[i]=='-'){
            posFlag = false;
            i++;
        } else if (s[i]=='+'){
            i++;
        }       
        // rest of string
        for (i;i<s.size();++i){
            if (s[i]==0 && res==0){
                continue;
            }else if (s[i]>='0' && s[i]<='9'){
                res = res*10+(s[i]-'0');
            }else{
                break;
            }
        }
        if (!posFlag){
            res = -res;
        }
        if (res> INT_MAX) return INT_MAX;
        if (res<INT_MIN) return INT_MIN;
        return res;
    }
};
