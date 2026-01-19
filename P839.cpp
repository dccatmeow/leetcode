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
        strsPtr = &strs;
        int sz = strs.size();
        parent.resize(sz);
        // initialize parent
        for (int i=0; i<sz;++i) parent[i] = i;
        // compare all the elements in strs
        for (int i=0;i<sz-1;++i){
            for (int j=i+1;j<sz;++j){
                if (isSimilar(strs[i], strs[j])){
                    unite(i,j);
                }
            }
        }
        unordered_set<int> groups;
        for (int i = 0; i < sz; i++) {
            groups.insert(findP(i));
        }
        return groups.size();
    }
    bool isSimilar(string& s1, string& s2){
        // O(n)
        int sz1 = s1.size();
        int sz2 = s2.size();
        if (sz1!=sz2) return false;
        vector<int> pos;
        for (int i=0;i<sz1;++i){
            if (s1[i]!=s2[i]){
                pos.push_back(i);
            }
            if (pos.size()>2) return false;
        }
        if (pos.empty()) return true;
        if (pos.size()==2 && s1[pos[0]==s2[pos[1]]]) return true;
        return false;
    }
    void unite(int s1, int s2){
        int p1 = findP(s1);
        int p2 = findP(s2);
        if (p1<p2){
            parent[p2] = p1;
        }else if (p1>p2){
            parent[p1] = p2;
        }
    }
    int findP(int s){
        if (parent[s]!=s){
            parent[s] = findP(parent[s]);
        }
        return parent[s];
    }
    
private:
    vector<int> parent;
    vector<string>* strsPtr;
};
/*
Time
Pair comparisons: O(N²)
Similarity check: O(L)
 Total: O(N² × L)

 Space
Union-Find parent array: O(N)
Total: O(N)
    */
