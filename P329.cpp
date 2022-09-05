/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary 
(i.e., wrap-around is not allowed).

Example 1:

Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // initialize
        m = matrix.size();
        n = matrix[0].size();
        res = 1;
        mem.resize(matrix.size());
        std::fill(mem.begin(), mem.end(), vector<int>(n,0));
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (mem[i][j]!=0){
                    // visited node
                    continue;
                }else{
                    tr(matrix, i, j);
                }
            }
        }
        return res;
    }
    vector<pair<int,int>> direction{{0,1},{1,0},{0,-1},{-1,0}};
    int tr(vector<vector<int>>& matrix, int i, int j){
        // traverse matrix starting from i, j and 
        // return the longest increasing path
        if (mem[i][j]!=0){
            // visited [i,j]
            return mem[i][j];
        }
        int tmp=1;
        for (auto [p,q]:direction){
            p +=i;
            q+=j;
            if (p>m-1||q>n-1||p<0||q<0){
                // out of boundary
                continue;
            }
            if (matrix[i][j]<matrix[p][q]){
                tmp = max(tmp, tr(matrix,p,q)+1);
            }
        }
        mem[i][j] = tmp;
        // update global max increasing path
        res = max(res, tmp);
        return tmp;
    }
private:
    vector<vector<int>> mem;
    int m;
    int n;
    int res;
};
