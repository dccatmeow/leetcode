/*242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for (auto e:s){
            m[e]++;
        }
        for (auto e:t){
            m[e]--;
        }
        for (auto [key,val]:m){
            if (val!=0){
                return false;
            }
        }
        return true;
    }
};
