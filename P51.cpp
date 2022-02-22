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
        //back track
        num = n;
        vector<string> tmp;
        bt(tmp);
        return res;
    }
    void bt(vector<string>& tmp){
        if (tmp.size() == num){
            res.push_back(tmp);
            return;
        }
        for (int i=0; i<num; ++i){
            if (!isValid(tmp, i)){
                continue;
            }else{
                // can place a queen
                string s(num, '.');
                s[i] = 'Q';
                tmp.push_back(s);
                bt(tmp);
                tmp.pop_back();
            }
        }
    }
    
    bool isValid(vector<string>& tmp,int i){
        for (int j = tmp.size()-1; j>=0; --j){
            // string is tmp[j]
            // up
            if (tmp[j][i] == 'Q'){
                return false;
            }
            // left up 
            int k = i- (tmp.size()-j);
            if (k>=0 && tmp[j][k] == 'Q'){
                return false;
            }
            // right up
            k = i+ (tmp.size() - j);
            if (k<num && tmp[j][k] == 'Q'){
                return false;
            }
        }
        return true;
    }
    
    
private:
    vector<vector<string>> res;
    int num;
};

// time complexity O(N!)     T(N) = O(N2) + N*T(N-1)
// space complexity O(n^2)
