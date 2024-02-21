class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res, tmp;
        unordered_set<string> strSet(wordDict.begin(), wordDict.end());
        bt(s,res,strSet,tmp);
        return res;
    }

    void bt(string s, vector<string>& res, unordered_set<string>& strSet, vector<string>& tmp){
        if (s.empty()){
            string str;
            for(auto e:tmp){
                str = str+e+" ";
            }
            str.pop_back();
            res.push_back(str);
        }

        for (int i=0; i<s.size();++i){
            if (strSet.find(s.substr(0,i+1))!=strSet.end()){
                tmp.push_back(s.substr(0,i+1));
                bt(s.substr(i+1), res, strSet, tmp);
                tmp.pop_back();
            }
        }
    }
};
