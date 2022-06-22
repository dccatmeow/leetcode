/*
he thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree.
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
*/

/**
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
    using pii = pair<int,int>;
    int rob(TreeNode* root) {
        // rob root, then cannot rob left or right child
        // not rob root, then can rob both left and right child
        auto [r, nr] = robT(root);
        return max(r, nr);
    }
    // return [rob max value, not rob max value]
    pii robT(TreeNode *root){
        // rob current node
        if (root == nullptr){
            return pii(0,0);
        }
        auto [lr, lnr] = robT(root->left);
        auto [rr, rnr] = robT(root->right);
        int r = root->val + lnr + rnr;
        int nr = max(rr, rnr) + max(lr, lnr);
        return pii(r, nr);
    }
};
