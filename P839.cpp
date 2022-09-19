/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. 
Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, 
but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  
Notice that "tars" and "arts" are in the same group even though they are not similar.  
Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
*/

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        // union find
        int n=strs.size();
        // initialize parent vector
        p = vector<int>(n, -1);
        for (int i=0; i<n; ++i){
            p[i] = i;
        }
        int res(n);
        // union for all the pair of strs
        for (int i=0; i<n; ++i){
            for (int j=i+1; j<n; ++j){
                if (isSameGroup(strs[i], strs[j])){
                    if (Union(i, j)){
                        // everytime union is made, one group less.
                        res--;
                    }
                }
            }
        }
        return res;
    }
    
    bool isSameGroup(const string& s1, const string& s2){
        // s1 and s2 are anagram, they all have same characters
        // in different order
        int cnt(0);
        for (int i=0; i<s1.size(); ++i){
            if (s1[i]!=s2[i]){
                cnt++;
            }
        }
        if (cnt==2 || cnt ==0){
            return true;
        }
        return false;
    }
    
    bool Union(int i, int j){
        int pi = findp(i);
        int pj = findp(j);
        if (pi != pj){
            if (pi<pj){
                p[pj] = pi;
            }else{
                p[pi] = pj;
            }
            return true;
        }
        // if no union action happened, return false
        return false;
    }
    
    int findp(int i){
        int pi = p[i];
        if (pi==i){
            return i;
        }else{
            return findp(pi);
        }
    }
private:
    vector<int> p;
};
