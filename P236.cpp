/**
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node 
in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr){
            return nullptr;
        }
        if (root == p || root == q){
            return root;
        }
        
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        // case1: find element in left and right branch
        if (left == p && right == q){
            return root;
        }else if (left == q && right == p){
            return root;
        }
        // nothing found
        if (left == nullptr && right ==nullptr){
            return nullptr;
        }
        // find the common ancestor and pass as root, or find one element pass to upper tree node
        if (left == nullptr){
            return right;
        }else{
            return left;
        }
        return nullptr;
    }
};
// time complexity O(tree height)
// space complexity O(tree height)
