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
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        // save matched letter numbers between words[i] and words[j]
        int m=words.size();
        vector<vector<int>> matched(m, vector<int>(m, INT_MAX));
        for (int i=0; i<m; ++i){
            for (int j=0; j<m; ++j){
                if (i>j){
                    // already visited
                    matched[i][j] = matched[j][i];
                }else if (i<j){
                    matched[i][j] = compWords(words[i], words[j]);
                }   
            }
        }
        // create a init index vector for all the words
        vector<int> initIdx(m,0);
        for (int i=0; i<m; ++i){
            initIdx[i] = i;
        }
        // find best match words in selectedIdx
        int bestWordIdx = findBestWordIdx(matched, initIdx);
        int cnt = 0;
        while(cnt<30){
          //**********IMPORTANT******************
            // select words from pool has same matchGuess as bestWord
          // secret words is ae
          // ab ac ae bf
          // best word = ab 
          // matchGuess = 1 (ae and ab have same a)
          // selectedIdx should only include ab ac ae where it has same match 1 (a)
          // bf and ab has 0 match
            vector<int> selectedIdx;
            int matchGuess = master.guess(words[bestWordIdx]);
            cnt++;
            if (matchGuess == 6){
                return;
            }
            for (auto i:initIdx){
                if (matched[i][bestWordIdx] == matchGuess){
                    selectedIdx.push_back(i);
                }
            }
            // find best match words in selectedIdx
            bestWordIdx = findBestWordIdx(matched, selectedIdx);
            initIdx.clear();
            initIdx = std::move(selectedIdx);
            selectedIdx.clear();
        }
    }
    
    int findBestWordIdx(vector<vector<int>>& matched, vector<int>& selectedIdx){
        int sz = selectedIdx.size();
        int bestWordIdx = -1;
        int smallestDiff = INT_MAX;
        for (int i=0; i<sz; ++i){
            // diff count for each string compare against other words in the pool 
            vector<int> diff(6,0);
            for (int j=0; j<sz; ++j){
                if (i==j){
                    continue;
                }
                int tmp = matched[selectedIdx[i]][selectedIdx[j]];
                diff[tmp]++;
            }
            // find the max and min in diff
            int dmax=diff[0];
            int dmin = dmax;
            for (auto d:diff){
                dmax = max(dmax, d);
                dmin = min(dmin, d);
            }
            int tmp = dmax-dmin;
            if (tmp < smallestDiff){
                // find new best word index 
                smallestDiff = tmp;
                bestWordIdx = selectedIdx[i];
            }
        }
        return bestWordIdx;
    }
    
    int compWords(const string& s1, const string& s2){
        int res(0);
        for (int i=0; i<6; ++i){
            if (s1[i]==s2[i]){
                res++;
            }
        }
        return res;
    }
};
