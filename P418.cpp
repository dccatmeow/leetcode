/*
Given a rows x cols screen and a sentence represented as a list of strings, return the number of times the given sentence can be fitted on the screen.

The order of words in the sentence must remain unchanged, and a word cannot be split into two lines. 
A single space must separate two consecutive words in a line.

Example 1:

Input: sentence = ["hello","world"], rows = 2, cols = 8
Output: 1
*/

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        // m[i] = nums, i is idx corresponding sentence[i]
        // nums is how many words in one row followed by sentence[i]
        unordered_map<int, int> m;
        int n = sentence.size();
        int i(0); // sentence[i]
        int cnt(0);
        for (int j=0; j<rows; ++j){
            if (!m.count(i)){
                // starting from sentence[j] at beginning of current row
                int tmp(cols);
                int tmpCnt(0);
                int previ = i; // keep track i
                while(tmp>=0){
                    if (i==n){
                        // restart from 0 position
                        i=0;
                    }
                    if (tmp >= sentence[i].size()){
                        tmp -= sentence[i].size()+1;
                        tmpCnt++;
                        i++;
                    }else{
                        break;
                    }
                }
                m[previ] = tmpCnt;
                cnt += m[previ];
            }else{
                cnt += m[i];
                // update i
                i = (i+m[i])%n;
            }
        }
        return cnt/n;
    }
};
