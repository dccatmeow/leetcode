/**
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path 
such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

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
    using pii=std::pair<int,int>;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root== nullptr){
            return false;
        }
        target = targetSum;
        return pathSum(root, 0);
    }

    bool pathSum(TreeNode* node, int s){
        if (node->left == nullptr && node->right == nullptr){
            if (s+node->val == target){
                return true;
            }else{
                return false;
            }
        }
        if (node->left != nullptr && pathSum(node->left, s+node->val)){
            return true;
        }
        if (node->right != nullptr && pathSum(node->right, s+node->val)){
            return true;
        }
        return false;
    }
private:
    int target;
};
