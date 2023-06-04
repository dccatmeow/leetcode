/*
745. Prefix and Suffix Search
Design a special dictionary that searches the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string pref, string suff) Returns the index of the word in the dictionary, which has the prefix pref and the suffix suff. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 

Example 1:

Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]
*/


class WordFilter {
public:
    WordFilter(vector<string>& words) {
        int n=words.size();
        for (int i=0; i<n;++i){
            int sz = words[i].size();
            for (int j=1; j<=sz; ++j){
                // all the possible prefix
                // 0....j-1
                string p = words[i].substr(0,j);
                for(int k=0; k<sz; ++k){
                    // all the possible suffix
                    // j.....
                    string s = words[i].substr(k,sz-k);
                    m[p + "|" + s]=i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        // tmp has all the possible match
        string s = pref+"|"+suff;
        if (m.find(s)!=m.end()){
            return m[s];
        }else{
            return -1;
        }
    }
    private:
    unordered_map<string,int> m;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
