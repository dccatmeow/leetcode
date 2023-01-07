/*
Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself 
(i.e. it can be written as a + a where a is some string).

Example 1:

Input: text = "abcabcabc"
Output: 3
Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
*/

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        // hashing 
        int p = 1000000007;
        unordered_set<string> res;
        int n = text.size();
        // rolling hash 0,...,i
        // 1, 26, 26*26.....
        vector<long long> multi(n,1);
        for (int i=1; i<n;++i){
            multi[i] = (multi[i-1])*26%p;
            
        }
        // hash text string
        // add a dummy 0 for presum[0]
        // text[0] corresponding presum[1]
        vector<long long> presum(n+1,0);
        for (int i=0; i<n;++i){
            // calculate each letter position and hash
            presum[i+1] = ( (text[i]-'a')*multi[i]%p + presum[i])%p;
        }
        for (int i=0; i<n; ++i){
            for (int j=i+1; j<=n-(j-i); ++j){
                if (text[i] == text[j]){
                    // same starting letter
                    // calculate hash value of two sub-string
                    // ...i...j...k
                    // j-1 - (i-1)
                    // k - (j-1)
                    int k = 2*j-i-1;
                    int num1 = (presum[j]-presum[i]+p)*multi[j-i]%p;
                    int num2 = (presum[k+1]-presum[j]+p)%p;
                    if(num1== num2){
                        // find potential match
                        // check real string
                        string str1 = text.substr(i, j-i);
                        string str2 = text.substr(j, j-i);
                        if (str1.compare(str2) == 0){
                            res.insert(str1);
                        }
                    }
                }
            }
        }
        return res.size();
    }
};
