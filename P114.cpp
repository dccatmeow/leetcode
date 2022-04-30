/**
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
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
    void flatten(TreeNode* root) {
        if (root==nullptr){
            return;
        }
        // flatten left node and right node first by recursive call
        flatten(root->left);
        flatten(root->right);
        // make left node to right, left node set to nullptr
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        // find the end of right and connect tmp
        while(root->right!=nullptr){
            root = root->right;
        }
        root->right = tmp;
    }
};
