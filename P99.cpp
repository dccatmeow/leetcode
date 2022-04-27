/**
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.
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
    void recoverTree(TreeNode* root) {
        // traverse tree using in-order print
        // for BST, in order traverse should return sorted value from low to high
        // switching random two number will cause 
        // one element greater than original value, shows when BST is violated
        // one element smaller than original value, shows later
        traverse(root);
        int tmp = first->val;
        first->val =second->val;
        second->val = tmp;
    }
    
    void traverse(TreeNode* node){
        if (node == nullptr){
            return;
        }
        traverse(node->left);
        
        // inorder check
        // find the first element violate BST
        if (first == nullptr && prev!=nullptr && prev->val>=node->val){
            // prev value is greater than node, so prev is the one that have issue
            first = prev;
        }
        // set second and keep find the ultimate smallest one that violate BST
        if (first!=nullptr && prev->val>=node->val){
            // find second element violate BST
            // node is the one that is smaller which is the one should be switched
            second = node;
        }
        prev = node;
        
        traverse(node->right);
    }
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
};
