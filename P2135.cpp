/*
You are given two 0-indexed arrays of strings startWords and targetWords. Each string consists of lowercase English letters only.

For each string in targetWords, check if it is possible to choose a string from startWords and perform a conversion operation on it 
to be equal to that from targetWords.

The conversion operation is described in the following two steps:

Append any lowercase letter that is not present in the string to its end.
For example, if the string is "abc", the letters 'd', 'e', or 'y' can be added to it, but not 'a'. If 'd' is added, the resulting string will be "abcd".
Rearrange the letters of the new string in any arbitrary order.
For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and so on. Note that it can also be rearranged to "abcd" itself.
Return the number of strings in targetWords that can be obtained by performing the operations on any string of startWords.

Note that you will only be verifying if the string in targetWords can be obtained from a string in startWords by performing the operations. 
The strings in startWords do not actually change during this process.

Example 1:

Input: startWords = ["ant","act","tack"], targetWords = ["tack","act","acti"]
Output: 2
*/

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        // bit mask
        unordered_set<int> ss;
        int res(0);
        // encode elements in startWords
        for (auto s:startWords){
            int tmp(0);
            for (auto c:s){
                tmp += 1 << (c-'a'); 
            }
            ss.insert(tmp);
        }
        // check in targetWords
        for (auto s:targetWords){
            for (int i=0; i<s.size();++i){
                // remove one character
                string stmp=s;
                stmp.erase(i,1);
                // encode stmp
                int tmp(0);
                for (auto c:stmp){
                    tmp += 1 << (c-'a'); 
                }
                // check if tmp is in ss
                if (ss.count(tmp)){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
