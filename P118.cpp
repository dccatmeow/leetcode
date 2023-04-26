// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        // first row 0
        res.push_back(vector<int>(1,1));
        // row 1 to numRows-1
        for (int i=1; i<numRows; ++i){
            vector<int> tmp(i+1,1);
            for (int j=1; j<i; ++j){
                tmp[j] = res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
