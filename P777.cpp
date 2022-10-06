/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", 
a move consists of either replacing one occurrence of "XL" with "LX", 
or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, 
return True if and only if there exists a sequence of moves to transform one string to the other.

Example 1:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: true
Explanation: We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
*/

class Solution {

public:
    bool canTransform(string start, string end) {
        // XL->LX; RX->XR
        // L can move forward and R can move backward
        // count l and r for L and R
        int l(0);
        int r(0);
        // removing X is s and e for start and end
        string s,e;
        int n=start.size();
        for (int i=0; i<n; ++i){
            if (start[i] !='X'){
                // without 'X'
                s = s+start[i];
                if (start[i] == 'L'){
                    l++;
                }else if (start[i] == 'R'){
                    r++;
                }
            }
            if (end[i] !='X'){
                e = e+end[i];
                if (end[i]=='L'){
                    l--;
                }else if (end[i]=='R'){
                    r--;
                }
            }
            // because start = LX end = XL is not allowed
            // l<=0 as L can be shift forward, but not backward
            if (l>0){
                return false;
            }
            // because start=XR end=RX is not allowed
            //  R can be shift backward, not forward
            if (r<0){
                return false;
            }
        }
        if (s!=e){
            // L and R not match
            // without 'X' start and end should be identical
            return false;
        }
        return true;
    }
};
