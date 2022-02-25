/* 37. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // starting from i = 0, j=0
        bt(board, 0, 0);
    }
    
    bool bt(vector<vector<char>>& board, int i, int j){
        // exit criteria
        if (i==9){
            // i=9, j=0
            return true;
        }
        if (j==9){
            return bt(board, i+1, 0);
        }
        if (board[i][j]!='.'){
            // move to next number
            return bt(board, i, j+1);
        }
        for (char k='1'; k<='9'; ++k){
            if (isValid(board, i, j, k)){
                board[i][j] = k;
                if (bt(board, i, j+1)){
                    return true;
                }
                board[i][j] = '.';
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j, char k){
        for (int p = 0; p<9; ++p){
            if (board[i][p] == k){
                return false;
            }
            if (board[p][j] == k){
                return false;
            }
        }
        
        int x = 3*(i/3);
        int y = 3*(j/3);
        for (int p=x; p<x+3; ++p){
            for (int q=y; q<y+3; ++q){
                if (board[p][q] == k){
                    return false;
                }
            }
        }
        return true;
    }
};
