/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // calculate each row up to form a histogram graph
        // then calculate the maximum rectangle for histogram on each row #84
        int m=matrix.size();
        int n=matrix[0].size();
        int res(0);
        // add one more element to make sure all element are calculated
        vector<int> height(n+1,0);
        for (auto v: matrix){
            for (int i=0; i<n; ++i){
                if (v[i] == '0'){
                    // reset histogram element
                    height[i]=0;
                }else{
                    // '1' case
                    height[i]++;
                }
            }
            stack<int> stk;
            for (int i=0; i<height.size(); ++i){
                while(!stk.empty() && height[stk.top()]>height[i]){
                    int tmp = height[stk.top()];
                    stk.pop();
                    if (stk.empty()){
                        res = max(res, tmp*i);
                    }else{
                        res = max(res,tmp*(i-stk.top()-1));
                    }
                }
                stk.push(i);
            }
        }
        return res;
    }
};
