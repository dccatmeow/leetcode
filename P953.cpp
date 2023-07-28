/*
953. Verifying an Alien Dictionary

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i=0; i<words.size()-1;++i){
            string word1 = words[i];
            string word2 = words[i+1];
            int p(0);
            while(word1[p]==word2[p]){
                p++;
                if (p==word1.size()||p==word2.size()){
                    break;
                }
            }
            int n1 = order.find(word1[p]);
            int n2 = order.find(word2[p]);
            if (n1>n2){
                return false;
            }
        }
        return true;
    }
};
