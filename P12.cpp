/*
12. Integer to Roman
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.

*/

class Solution {
public:
    string intToRoman(int num) {
        string res;
        string key="MDCLXVI";
        vector<int> div{1000,500,100,50,10,5,1};
        for (int i=0; i<div.size();i=i+2){
            int tmp = num/div[i];
            num = num%div[i];
            if (tmp==0){
                continue;
            }else if (tmp>0&& tmp<4){
                for (int j=0;j<tmp;++j){
                    res = res+key[i];
                }
            }else if (tmp==4){ // num<3999
                res = res+key[i]+key[i-1];
            }else if (tmp==5){
                res = res+key[i-1];
            }else if (tmp>5 && tmp<9){
                res = res+key[i-1];
                 for (int j=0;j<tmp-5;++j){
                    res = res+key[i];
                }
            }else if (tmp==9){
                res = res+key[i]+key[i-2];
            }
        }
        return res;
    }
};
