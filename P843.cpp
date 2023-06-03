/**
You are given an array of unique strings words where words[i] is six letters long. One word of words was chosen as a secret word.

You are also given the helper object Master. You may call Master.guess(word) where word is a six-letter-long string, and it must be from words. 
Master.guess(word) returns:

-1 if word is not from words, or
an integer representing the number of exact matches (value and position) of your guess to the secret word.
There is a parameter allowedGuesses for each test case where allowedGuesses is the maximum number of times you can call Master.guess(word).

For each test case, you should call Master.guess with the secret word without exceeding the maximum number of allowed guesses. You will get:

"Either you took too many guesses, or you did not find the secret word." if you called Master.guess more than allowedGuesses times 
or if you did not call Master.guess with the secret word, or
"You guessed the secret word correctly." if you called Master.guess with the secret word with the number of calls to Master.guess l
ess than or equal to allowedGuesses.
The test cases are generated such that you can guess the secret word with a reasonable strategy (other than using the bruteforce method).

Example 1:

Input: secret = "acckzz", words = ["acckzz","ccbazz","eiowzz","abcczz"], allowedGuesses = 10
Output: You guessed the secret word correctly.

 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        // build graph for words match
        int n=words.size();
        vector<vector<int>> g(n, vector<int>(n,0));
        for (int i=0; i<n; ++i){
            g[i][i] = 6;
            for (int j=i; j<n; ++j){
                int cnt(0);
                for (int k=0; k<6;++k){
                    if (words[i][k]==words[j][k]){
                        ++cnt;
                    }
                }
                g[i][j]=cnt;
                g[j][i] = cnt;
            }
        }
        // secret words should have same match as tmp
        unordered_set<int> res;
        unordered_set<int> tmp;
        int match = master.guess(words[0]);
        if (match == 6){
            return;
        }
        for (int i=0; i<n; ++i){
            if (match == g[0][i]){
                res.insert(i);
            }
        }

        while(!res.empty()){
            int i= *res.begin();
            match = master.guess(words[i]);
            if (match == 6){
                return;
            }else{
                res.erase(i);
            }
            for (auto e:res){                
                if (match == g[e][i]){
                    tmp.insert(e);
                }
            }
            res.clear();
            res = std::move(tmp);
        }
    }
};
