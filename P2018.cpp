/*
You are given an m x n matrix board, representing the current state of a crossword puzzle. The crossword contains 
lowercase English letters (from solved words), ' ' to represent any empty cells, and '#' to represent any blocked cells.

A word can be placed horizontally (left to right or right to left) or vertically (top to bottom or bottom to top) in the board if:

It does not occupy a cell containing the character '#'.
The cell each letter is placed in must either be ' ' (empty) or match the letter already on the board.
There must not be any empty cells ' ' or other lowercase letters directly left or right of the word 
if the word was placed horizontally.
There must not be any empty cells ' ' or other lowercase letters directly above or below the word if the word was placed vertically.
Given a string word, return true if word can be placed in board, or false otherwise.

Example 1:

Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
Output: true
Explanation: The word "abc" can be placed as shown above (top to bottom).
*/

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        k=word.size();
        for (int i=0; i<m; ++i){
            // check rows
            int cnt(0);
            bool l(true);
            bool r(true);
            for (int j=0; j<n;++j){
                if(check(board, word, cnt, r, l, i, j)){
                    return true;
                }
            }
            if (cnt==k){ //***** check last cnt as it may not go through check
                return true;
            }
        }

        for (int i=0; i<n; ++i){
            // check rows
            int cnt(0);
            bool l(true);
            bool r(true);
            for (int j=0; j<m;++j){
                if(check(board, word, cnt, r, l, j, i)){
                    return true;
                }
            }
            if (cnt==k){
                return true;
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, string& word, int& cnt, bool& r, bool& l, int i, int j){
        if (board[i][j]=='#'){
            if (cnt==k){
                // find a place to put word
                return true;
            }
            cnt=0; // ***** reset all to begining
            l = true;
            r = true;
            return false;
        }else if (board[i][j]==' '){
            cnt++;
        }else{
            // characters
            if (cnt>=k){
                cnt = k+1;//*** no longer a valid solution
                return false;
            }
            // no match found in word
            if (board[i][j]!=word[cnt]){
                l=false;
            }
            if (board[i][j]!=word[k-1-cnt]){
                r=false;
            }
            // left or right direction has a matching character
            // only two possible way to increment cnt by 1
            if (l && board[i][j]==word[cnt]){
                cnt++;
            }else if (r && board[i][j]==word[k-1-cnt]){
                cnt++;
            }else {
                cnt = k+1;// no longer a valid solution
            }
        }
        return false;
    }
private:
    int m;
    int n;
    int k;
};
