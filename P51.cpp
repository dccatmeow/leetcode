/* 51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // back track
        sz = n;
        vector<string> tmp(n, string(n, '.'));
        bt(tmp, 0);
        return res;
    }
    
    void bt(vector<string>& v, int i){
        // find a position in row i for v
        // exit condition
        if (i==sz){
            res.push_back(v);
        }
        // iterate through all the j [0,sz)
        for (int j=0; j<sz; ++j){
            if(isValid(v, i, j)){
                v[i][j] = 'Q';
                bt(v, i+1);
                v[i][j] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& v, int i, int j){
        for (int k=i-1; k>=0; --k){
            // up direction
            if (v[k][j] == 'Q'){
                return false;
            }
        }
        for(int k=1; k<=i; ++k){
            // up left
            if (j-k>=0 && v[i-k][j-k] == 'Q'){
                return false;
            }
            // up right
            if (j+k<sz && v[i-k][j+k] == 'Q'){
                return false;
            }
        }
        return true;
    }
    
private:
    vector<vector<string>> res;
    int sz;
};

// time complexity O(N!)     T(N) = O(N2) + N*T(N-1)
// space complexity O(n^2)
