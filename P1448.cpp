/**
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

Example 1:

Input: root = [3,1,4,3,null,1,5]
Output: 4

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
    int goodNodes(TreeNode* root) {
        res = 0;
        tr(root, root->val);
        return res;
    }
    void tr(TreeNode* node, int v){
        // current TreeNode, max value from root before current node
        if (node == nullptr){
            return;
        }
        if (node->val>=v){
            res++;
        }
        tr(node->left, max(v,node->val));
        tr(node->right, max(v, node->val));
    }
private:
    int res;
};
