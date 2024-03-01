/**
107. Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root==nullptr){
            return {};
        }
        std::queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int n=q.size();
            vector<int> tmp(n,0);
            for (int i=0; i<n; ++i){
                auto node = q.front();
                q.pop();
                tmp[i]=node->val;
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            res.push_back(std::move(tmp));
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
