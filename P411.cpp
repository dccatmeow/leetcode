/*
411. Minimum Unique Word Abbreviation
A string can be abbreviated by replacing any number of non-adjacent substrings with their lengths. For example, a string such as "substitution" could be abbreviated as (but not limited to):

"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)
Note that "s55n" ("s ubsti tutio n") is not a valid abbreviation of "substitution" because the replaced substrings are adjacent.

The length of an abbreviation is the number of letters that were not replaced plus the number of substrings that were replaced. For example, the abbreviation "s10n" has a length of 3 (2 letters + 1 substring) and "su3i1u2on" has a length of 9 (6 letters + 3 substrings).

Given a target string target and an array of strings dictionary, return an abbreviation of target with the shortest possible length such that it is not an abbreviation of any string in dictionary. If there are multiple shortest abbreviations, return any of them.

Example 1:

Input: target = "apple", dictionary = ["blade"]
Output: "a4"
*/

class Solution {
public:
    int sz;
    int maxn; // 1000000, number of 0 is the size of target
    int minlen;
    int minab; // places that need to use letter, 1

    vector<int> dict;
    string minAbbreviation(string target, vector<string>& dictionary) {
        sz = target.size();
        maxn = 1 << sz;
        minlen = INT_MAX;
        string res;

        // Preprocessing with bit manipulation
        for (auto w : dictionary) {
            // not same length do not have conflict
            if (w.size() != sz) continue;

            int word = 0;
            // label if letters are different compared against target with 1
            // at least 1 bit in word should remain to make sure word is difference against target
            for (int i = sz-1, bit = 1; i >= 0; --i, bit = bit<<1){
                if (target[i] != w[i]){
                     word += bit;
                }
            }
            dict.push_back(word);
            // use bit or operation to get all the 1 that is possible for letter position
        }
        findShortest();

        // Reconstruct abbreviation from bit sequence
        for (int i = sz-1, pre = i; i >= 0; --i, minab = minab>>1) {
            // check if current position needs to be letter
            if (minab & 1) {
                if (pre-i > 0){
                    // calculate number of replaced letters i....pre
                    res = to_string(pre-i) + res;
                }
                pre = i - 1;
                // letter+res
                res = target[i] + res;
            }
            else if (i == 0){
                 res = to_string(pre-i+1) + res;
            }
        }
        return res;
    }

    void findShortest(){
        for (int i=0; i<maxn;++i ){
            int len = abbrLen(i);
            if (len >= minlen) continue;
            bool match = true;
            for (auto word:dict){
                // word   abbba
                // target aaaaa
                // e.g. mask 10010, 1 means place need to use letter
                //      word 01110, 1 means different letter against target
                if ( (i&word)==0 ){
                    // current mask&word can be represent using same abbrevation, invalid case
                    // e,g, mask 10001, a3a
                    match = false;
                }
            }
            if (match){
                minlen = len;
                minab = i;
            }
        }
    }

    // Return the length of abbreviation given bit sequence
    // baaab mask 10011 return 4 a2ba
    int abbrLen(int mask) {
        int count = 0;
        for (int b = 1; b < maxn;) {
            if ((mask & b) == 0){
                // skip all the 0
                while(b<maxn){
                    // loop and shift 1 to left until b and mask has common 1 in positions
                    if ((mask & b) == 0){
                        // keep increasing b by shift 1 to left
                        b = b<<1;
                    }else{
                        break;
                    }
                }
            }else{ 
                b <<= 1;
            }
            count ++;
        }
        return count;
    }
};
