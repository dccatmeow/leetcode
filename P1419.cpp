/*
You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, 
that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.

Return the minimum number of different frogs to finish all the croaks in the given string.

A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. 
The frogs have to print all five letters to finish a croak. If the given string is not a combination of 
a valid "croak" return -1.

 

Example 1:

Input: croakOfFrogs = "croakcroak"
Output: 1 
Explanation: One frog yelling "croak" twice.
*/

class Solution {
public:
    bool isValid(unordered_map<char,int>& m){
        if (m['c']>=m['r']&& m['r']>=m['o']&&m['o']>=m['a']
        && m['a']>=m['k']){
            return true;
        }
        return false;
    }
    int minNumberOfFrogs(string croakOfFrogs) {
        //When a frog sings 'c', we increase the number of (simultaneous) frogs.
        //when a frog sings 'k', we decrease the number of (simultaneous) frogs.
        unordered_map<char,int> m;
        m['c'] = 0;
        m['r'] = 0;
        m['o'] = 0;
        m['a'] = 0;
        m['k'] = 0;
        int numFrog(0), res(0);
        for (auto c:croakOfFrogs){
            // add to hash table
            if (m.count(c)){
                m[c]++;
            }
            // 'croak' if c shows up, then a new frog is here
            // if k shows up then a frog finished croak, remove one
            if (c == 'c'){
                // new frog
                numFrog++;
                res = max(res,numFrog);
            }else if (c == 'k'){
                numFrog--;
            }
            // check status of current string parsing
            if (!isValid(m)){
                return -1;
            }
        }
        if (numFrog == 0){
            return res;
        }
        return -1;
    }
};
