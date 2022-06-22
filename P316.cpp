/*
Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26);
        // use vector as a stack
        vector<int> stac;
        string res;
        // use visited flag to avoid add letter into stack multiple times
        vector<bool> inStack(26);
        for (auto i:s){
            count[i-'a']++;
        }
        for(auto i:s){
            if (inStack[i-'a']){
                count[i-'a']--;
                continue;
            }
            while (!stac.empty() && (i-'a')<stac.back() && count[stac.back()]>0){
                // new letter is lexicographical small and previous letter has more to be visited
                inStack[stac.back()] = false;
                stac.pop_back();
            }
            stac.push_back(i-'a');
            inStack[i-'a'] = true;
            count[i-'a']--;
        }
        for (auto i:stac){
            res = res+char('a'+i);
        }
        return res;
    }
};
