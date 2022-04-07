/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
*/

class Solution {
public:
    string convert(string s, int numRows) {
        int n = 2*numRows-2;
        if (n == 0){
            return s;
        }
        string res;
        int j=0;
        // first row
        while(j<s.size()){
            res.push_back(s[j]);
            j = j+n;
        }
        // middle rows
        for (j=1; j<numRows-1;++j){
            int tmp = j;
            while(tmp<s.size()){
                // first element in this set
                res.push_back(s[tmp]);
                // second element in this set
                int tmp1 = tmp+n-2*j;
                if (tmp1 < s.size()){
                    res.push_back(s[tmp1]);
                }
                tmp = tmp+n;
            }
        }
        // last row
        j = numRows-1;
        while(j<s.size()){
            res.push_back(s[j]);
            j = j+n;
        }
        
        return res;
    }
};
