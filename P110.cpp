/**
110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

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
    bool isBalanced(TreeNode* root) {
        // initialize
        res = true;
        auto tmp = traverse(root);
        return res;
    }
    
    int traverse(TreeNode* root){
        // return the number of layers in tree root
        if (root== nullptr){
            return 0;
        }
        auto left = traverse(root->left);
        auto right = traverse(root->right);
        if (abs(left - right) >1){
            res = false;
        }
        return max(left, right)+1;
    }
private:
    bool res;
};
