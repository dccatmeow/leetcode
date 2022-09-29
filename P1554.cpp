/*
Given a list of strings dict where all the strings are of the same length.

Return true if there are 2 strings that only differ by 1 character in the same index, otherwise return false.
Example 1:

Input: dict = ["abcd","acbd", "aacd"]
Output: true
Explanation: Strings "abcd" and "aacd" differ only by one character in the index 1.
*/

class Solution {
public:
    using pii = std::pair<int,int>;
    bool differByOne(vector<string>& dict) {
        // save all the string by removing one character
        // use rolling hash, store hashed value and correspoding string in dict, character removed
        unordered_map<int, vector<pii>> m;
        int p = 1000000007; //*** a prime number use pow(10, 9)+7
        vector<int> multi; //*** save the multiply of 1, 26, 26*26....
        multi.push_back(1);
        
        for (int i=0; i<dict.size(); ++i){
            int tmp(0); //*** int
            int n = dict[i].size();
            for (int k=0; k<n;++k){
                // a            b         c     d
                // 0*26*26*26   1*26*26   2*26  3
                tmp = ((long)tmp*26%p + (dict[i][k]-'a') ) % p; //*** rolling hash
                if (k>multi.size()-1){
                    int tmp1 = ((long)multi[k-1]*26)%p;
                    multi.push_back(tmp1);
                }
            }
            for (int j=0; j<n;++j){
                // hash, skip j
                int tmp2 = ((long)(dict[i][j]-'a')*multi[n-1-j])%p;
                tmp2 = (tmp -tmp2 + p)%p; // to avoid negative number
                if (m.count(tmp2)){
                    // find possible match
                    for (auto& [pi, pj]:m[tmp2]){
                        if (i!=pi && j==pj){ //*** not the same string, at same position j
                            string s1 = dict[pi];
                            s1.erase(pj,1);
                            string s2 = dict[i];
                            s2.erase(j,1);
                            if (s1.compare(s2)==0){
                                // equal
                                return true;
                            }
                        }
                    }
                }
                m[tmp2].push_back(pii(i,j));
            }
        }
        return false;
    }
};
