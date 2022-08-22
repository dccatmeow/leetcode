/*
You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 
and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) 
that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
*/

class Solution {
public:
    vector<int> parent = vector<int>(26, -1);
    
    bool equationsPossible(vector<string>& equations) {
        // loop through all the equal relationship
        for (auto i:equations){
            if (i[1] == '='){
                // union
                unionStr(i[0],i[3]);
            }
        }
        
        // loop through all the inequal relationship
        for (auto i:equations){
            if (i[1] == '!'){
                int i1 = i[0] -'a';
                int i2 = i[3] - 'a';
                if (findParent(i1) == findParent(i2)){
                    return false;
                }
            }
        }
        return true;
    }
    
    int findParent(int i){
        if (parent[i]==-1 || parent[i] == i){
            return i;
        }else{
            parent[i] = findParent(parent[i]);
            return parent[i];
        }
    }
    
    void unionStr(char s1, char s2){
        // union root parent together
        int s1_int = s1-'a';
        int s2_int = s2-'a';
        int s1_parent = findParent(s1_int);
        int s2_parent = findParent(s2_int);
        parent[s1_parent] = s2_parent;
    }
    
};
