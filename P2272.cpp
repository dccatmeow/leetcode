/*
The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "aababbb"
Output: 3
Explanation:
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.
*/

class Solution {
public:
    int largestVariance(string s) {
        // calculate variance for a pair of letters in s
        // count difference between m and n
        // case 1: m is 1 and n is -1, at least one n should exist
        vector<int> count(26,0);
        for (auto c:s){
            // all lower case letter
            int i = c-'a';
            count[i]++;
        }
        for (int i=0; i<26; ++i){
            if (count[i]==0){
                // letter not in s
                continue;
            }
            for (int j=i+1; j<26;++j){
                if (count[j]==0){
                    // letter not in s
                    continue;
                }
                calVariance(s,'a'+i,'a'+j);
                calVariance(s,'a'+j,'a'+i);
            }
        }
        return res;
    }
    void calVariance(string s, char m, char n){
        // calculate variance between m, n
        // substring begin with m
        int cnt(0);
        bool flagn(false);
        bool initn(false);
        for (char c:s){
            if (c == m){
                cnt++;
            }else if (c==n){
                flagn = true;
                if (initn && cnt>=0){
                    // has n as initial letter
                    // now we can safely remove that initial letter
                    // add cnt back by 1
                    cnt++;
                    initn = false;
                }
                cnt--;
            }
            if (cnt<0){
                // leave one n as initial, in case no j shows up in the future
                cnt = -1;
                initn = true;
            }else if (flagn){
                res = max(res, cnt);
            }
        }
    }
private:
    int res{0};
};
