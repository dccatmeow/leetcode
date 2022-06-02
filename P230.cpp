/**
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


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
    // in-order traverse print out BST is increasing order of numbers
    int rank = 1;
    int res;
    int kthSmallest(TreeNode* root, int k) {
        tr(root, k);
        return res;
    }
    
    void tr(TreeNode* n, int k){
        if (n == nullptr || rank > k){
            return;
        }
        tr(n->left, k);
        if (rank == k){
            res = n->val;
        }
        rank++;
        tr(n->right, k);
    }
};
// time complexity O(tree height) 
// space complexity O(tree height) 
