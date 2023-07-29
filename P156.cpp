/**
156. Binary Tree Upside Down
You can turn a binary tree upside down with the following steps:

The original left child becomes the new root.
The original root becomes the new right child.
The original right child becomes the new left child.

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
TreeNode* helper(TreeNode* root, TreeNode* parent, TreeNode* sibling)
    {
        if(root==nullptr)
            return parent;
        
        TreeNode* tempLeft  = root->left;
        TreeNode* tempRight = root->right;
        
        root->right = parent;
        root->left = sibling;
        
        return helper(tempLeft, root, tempRight);
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }
};
