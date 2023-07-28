/*
249. Group Shifted Strings

We can shift a string by shifting each of its letters to its successive letter.

For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.

For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

 

Example 1:

Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<int>> m;
        for (int i=0; i<strings.size();++i){
            int delta  = strings[i][0]-'a';
            string key;
            for (auto e:strings[i]){
                char c = 'a'+(e-'a'-delta+26)%26;
                key = key + c;
            }
            m[key].push_back(i);
        }
        vector<vector<string>> res;
        for (auto& elem:m){
            vector<string> tmp;
            for (auto idx:elem.second){
                tmp.push_back(strings[idx]);
            }
            res.push_back(std::move(tmp));
        }
        return res;
    }
};
