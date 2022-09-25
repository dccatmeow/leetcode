/*
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. 
If the task is impossible, return -1.

Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
*/
class Solution {
public:
    int shortestWay(string source, string target) {
        // use a map for character loop up its position in source
        unordered_map<char,vector<int>> m;
        for (int i=0; i<source.size();++i){
            m[source[i]].push_back(i);
        }
        int res(0);
        int prev(-1);
        for (int i=0; i<target.size();++i){
            if (!m.count(target[i])){
                // no matching alphabet in source
                return -1;
            }
            bool flag(false);
            for (auto j:m[target[i]]){
                if (prev<j){
                    prev = j;
                    flag=true;
                    break;
                }
            }
            if (!flag){
                // need to restart with a new substring
                //set prev to smallest position with target[i] value
                res++;
                prev = m[target[i]][0];
            }
        }
        res++;
        return res;
    }
};
