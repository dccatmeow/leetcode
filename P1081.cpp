/*
Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
Example 1:

Input: s = "bcabc"
Output: "abc"
*/

class Solution {
public:
    string smallestSubsequence(string s) {
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
