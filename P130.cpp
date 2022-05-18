/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // loop through all the boardary and find o 
        // do a dfs to find all the connected o, put it to .
        // put the rest o in board to x
        // put . to o
        int m=board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i=0; i<m; ++i){
            if (board[i][0] == 'O'){
                dfs(board, visited, i, 0);
            }
            if (board[i][n-1]=='O'){
                dfs(board, visited, i, n-1);
            }
        }
        for (int j=0; j<n; ++j){
            if (board[0][j] == 'O'){
                dfs(board, visited, 0, j);
            }
            if (board[m-1][j]=='O'){
                dfs(board, visited, m-1, j);
            }
        }
        for (int i=0; i<m; i++){
            for (int j=0; j<n; ++j){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if (board[i][j] == '.'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        if (i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            // exceed limit
            return;
        }
        if (visited[i][j]){
            return;
        }else{
            visited[i][j] = true;
        }
        if (board[i][j] == 'O'){
            board[i][j] = '.';
            dfs(board, visited, i+1, j);
            dfs(board, visited, i-1, j);
            dfs(board, visited, i, j+1);
            dfs(board, visited, i, j-1);
        }
    }
};
