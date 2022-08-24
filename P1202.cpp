/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
*/

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // union find collections
        int n = s.size();
        for (int i=0; i<n; ++i){
            parent.push_back(i);
        }
        for (auto p:pairs){
            int p0 = findP(p[0]);
            int p1 = findP(p[1]);
            if (p0<p1){
                parent[p1] = p0;
            }else{
                parent[p0] = p1;
            }
        }
        // get collections and store it in smallest element index in data
        vector<vector<int>> data(n, vector<int>());
        for (int i=0; i<n; ++i){
            data[findP(i)].push_back(i);
        }
        // loop through data and make arrangement
        for (auto v:data){
            if (v.empty()){
                continue;
            }
            string tmp;
            for (auto i:v){
                tmp.push_back(s[i]);
            }
            // sort string to lexicographical order
            sort(tmp.begin(), tmp.end());
            // place alphabet in tmp back to s
            for (int i=0; i<v.size(); ++i){
                s[v[i]] = tmp[i];
            }
        }
        
        return s;
    }
    int findP(int e){
        if (parent[e] == e){
            return e;
        }else{
            return findP(parent[e]);
        }
    }
private:
    vector<int> parent;
};
