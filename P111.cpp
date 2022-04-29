/**
111. Minimum Depth of Binary Tree

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
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        traverse(root, 1);
        return res;
    }
    
    void traverse(TreeNode* node, int count){
    // End condition is very important
        if (node->left == nullptr && node->right == nullptr){
            res = min(res,count);
            return;
        }
        count++;
        if (node->left!=nullptr){
            traverse(node->left, count);
        }
        if (node->right!=nullptr){
            traverse(node->right, count);
        }
    }
private:
    int res = INT_MAX;
};
