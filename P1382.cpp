/**
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]

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
private:
    vector<TreeNode *> sortedArray;
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return convertArrayToBST(0, sortedArray.size()-1);
    }
    
    void inorderTraverse(TreeNode* root){
        // middle order traversal to get the in order of tree nodes
        if (root == nullptr){
            return;
        }
        if (root->left) {
            inorderTraverse(root->left);
        }
        sortedArray.push_back(root);
        if(root->right){
            inorderTraverse(root->right);
        }
    }
    
    TreeNode* convertArrayToBST(int startP, int endP){
        if (startP > endP){
            return nullptr;
        }
        int midP = (startP+endP)/2;
        TreeNode* newRoot = sortedArray[midP];
        newRoot->left = convertArrayToBST(startP, midP-1);
        newRoot->right = convertArrayToBST(midP+1, endP);
        return newRoot;
    }
};
