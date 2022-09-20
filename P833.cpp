/*
You are given a 0-indexed string s that you must perform k replacement operations on. 
The replacement operations are given as three 0-indexed parallel arrays, indices, sources, and targets, all of length k.

To complete the ith replacement operation:

Check if the substring sources[i] occurs at index indices[i] in the original string s.
If it does not occur, do nothing.
Otherwise if it does occur, replace that substring with targets[i].
For example, if s = "abcd", indices[i] = 0, sources[i] = "ab", and targets[i] = "eee", then the result of this replacement will be "eeecd".

All replacement operations must occur simultaneously, meaning the replacement operations should not affect the indexing of each other. 
The testcases will be generated such that the replacements will not overlap.

For example, a testcase with s = "abc", indices = [0, 1], and sources = ["ab","bc"] will not be generated because the "ab" and "bc" replacements overlap.
Return the resulting string after performing all replacement operations on s.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: s = "abcd", indices = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
Output: "eeebffff"
Explanation:
"a" occurs at index 0 in s, so we replace it with "eee".
"cd" occurs at index 2 in s, so we replace it with "ffff".
*/

class Solution {
public:
    using pii= std::pair<int,int>;
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        // sort indices from right to left, so the index for s will not be impacted by the length of targets
        int n=indices.size();
        vector<pii> index(n, pii());
        // pii{ index for s, index for sources and targets}
        for (int i=0; i<indices.size(); ++i){
            index[i] = pii(indices[i], i);
        }
        // sort index first element, from largest to smallest
        sort(index.begin(), index.end(), greater());
        for (auto[i_s ,i]:index){
            // check if source is in s
            int idx = i_s;
            for (auto c:sources[i]){
                if (idx==s.size() || c!=s[idx]){
                    break;
                }
                idx++;
            }
            if(idx == i_s+sources[i].size()){
                // find a match for source in s at i_s
                // s[0]  i_s  i_s+source[i].size()-1 i_s+source[i];
                string front = s.substr(0, i_s);
                string en = s.substr(i_s+sources[i].size());
                s = front+ targets[i] +en;
            }
        }
        return s;
    }
};
