/*
77. Combinations
Medium

4052

140

Add to List

Share
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // back track with an argument input, start
        vector<int> v;
        bt(v, n, k, 1);
        return res;
    }
    void bt(vector<int>& v, int n, int k, int start){
        // end condition 
        if (v.size() == k){
            res.push_back(v);
            return;
        }
        for (int i=start; i<=n; ++i){
            v.push_back(i);
            bt(v,n,k, i+1);
            v.pop_back();
        }
    }
private: 
    vector<vector<int>> res;
    
};
