/**
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:

Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]

* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        // recursive call, iterate through all the possibility
        return gt(1, n);
    }
    
    vector<TreeNode*> gt(int c1, int c2){
        // this function return all the possible permutation of tree
        // between [c1, c2]
        vector<TreeNode*> res;
        if (c1 > c2){
            return {nullptr};
        }
        for (int i=c1; i<=c2;++i){
            // find left and right children
            auto v1 = gt(c1, i-1);
            auto v2 = gt(i+1, c2);
            for (auto e1:v1){
                for (auto e2:v2){
                    // purmutation of all the possible child tree
                    // root:i
                    // left child: e1
                    // right child: e2
                    res.push_back(new TreeNode(i, e1, e2));
                }
            }
        }
        return res;
    }
};
