/*
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int left(0), right(0);
        int n = s.size();
        int resL(0), resR(0);
        for (int i=0; i<s.size(); ++i){
            int tmp = i-1;
            right = i;
            left = i;
            // find the identical chars in the middle
            // use tmp to get exact left and right position
            while(tmp>=0 && s[tmp] == s[i]){
                    left = tmp;
                    tmp--;
            }
            tmp = i+1;
            while(tmp<n && s[tmp] == s[i]){
                    right = tmp;
                    tmp++;
            }
            // find mirroring element
            while(left>=0 && right<n && s[left]==s[right]){
                if (resR-resL < right-left){
                    resR=right;
                    resL=left;
                }
                left--;
                right++;
            }
        }
        return s.substr(resL, (resR-resL+1));
    }
};
