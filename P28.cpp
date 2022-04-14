/*
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int l(-1),i(0), j(0);
        while(i!=haystack.size()){
            if (j==0 && haystack[i] == needle[0]){
                // beginning of needle
                l = i;
                ++i;
                ++j;
                while(i<haystack.size() && j< needle.size() && haystack[i] == needle[j]){
                    i++;
                    j++;
                }
                if (j == needle.size()){
                    // find the correct l
                    return l;
                }else{
                    // reset
                    i = l+1;
                    l = -1;
                    j=0;
                }
            }else{
                ++i;
            }
        }
        return l;
    }
};
