/*
680. Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most one character from it.
Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        return isPalind(s,0, s.size()-1, 0);
    }
    bool isPalind(string& s, int i, int j, int cnt){
        if (cnt>1){
            return false;
        }
        while(i<j){
            if (s[i]!=s[j]){
                bool tf = isPalind(s, i+1,j, cnt+1)|| isPalind(s,i,j-1,cnt+1);
                return tf;
            }
            i++;
            j--;
        }
        return true;
    }
};
