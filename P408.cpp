/*
408. Valid Word Abbreviation
A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)
*/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i(0), j(0);
        while(i<word.size()&&j<abbr.size()){
            int num(0);
            if (word[i]!=abbr[j]){
                if (abbr[j]<'0' || abbr[j]>'9'){
                    return false;
                }
                if (abbr[j]=='0'){
                    // leading 0
                    return false;
                }
                while (abbr[j]>='0'&&abbr[j]<='9'){
                   num = num*10+(abbr[j]-'0');
                   ++j; 
                }
                // char after numbers
                i = i+num;
                if (i>word.size()){
                    // exceed word
                    return false;
                }else if (i==word.size()){
                    // word finished scan
                    break;
                }else{
                    // false cases
                    // abbr finished word not finished
                    // number followed by number
                    if (j==abbr.size() || word[i]!=abbr[j]){
                        return false;
                    }
                }
            }
            ++i;
            ++j;
        }
        if (i==word.size()&& j==abbr.size()){
            return true;
        }
        return false;
    }
};
