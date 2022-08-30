class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // memory to store string and predecessors length
        // e.g. a, ab, abc
        // m[a] = 1, m[ab] = 2, m[abc]=3
        unordered_map<string, int> m;
        // sort words from shortest to longest
        auto comp=[](const auto& s1, const auto& s2){
            return s1.size()<s2.size();
        };
        sort(words.begin(), words.end(), comp);
        int res(1);
        for (auto w:words){
            if (w == words[0]){
                m[words[0]] = 1;
                continue;
            }
            int k(1);
            for (int i=0; i<w.size();++i){
                // 0,....i-1, i, i+1.....
                // remove i
                // substr(0, i)  substr(i+1);
                string tmp = w.substr(0,i)+w.substr(i+1);
                if (m.count(tmp)){
                    // if w has predecessor
                    k = max(k, m[tmp]+1);
                }
            }
            m[w] = k;
            res = max(res,k);
        }
        return res;
    }
};
