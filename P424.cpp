/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int maxCount = 0;
        int res = 0;
        int l = 0;
        int sz=s.size();
        // count repeating times of each letter in string s
        for (int r = 0; r < sz; ++r){
            int idx = s[r]-'A';
            count[idx]++;         
            // calculate max count of repeating letter in sub-string
            if (count[idx] > maxCount){
                maxCount = count[idx];
            }
            
            // acceptable condition: 
            // sub-string size - maxCount <= k
            // otherwise we need to move begin of window
            if ((r - l + 1) - maxCount > k){
                count[s[l]-'A']--;
                l++;
            }
            
            // size of longest sub-string in current window = maxCount + k
            res = max(res, maxCount + k);
        }
        res = min(res, sz);
        return res;
    }
};
