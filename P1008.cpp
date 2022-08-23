/**
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, 
and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example 1:

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return createTree(preorder, 0, preorder.size()-1);
    }
    
    TreeNode* createTree(vector<int>& preorder, int s, int e){
        if (s==e){
            return new TreeNode(preorder[s]);
        }
        // the first element is root for preorder traversal
        auto root = new TreeNode(preorder[s]);
        // find the first element greater than preorder[s]
        auto it = lower_bound(preorder.begin()+s+1, preorder.begin()+e+1, preorder[s]);
        int m = it-preorder.begin();
        if (m-1>=s+1){
            root->left = createTree(preorder, s+1, m-1);
        }
        if (e>=m){
            root->right = createTree(preorder,  m, e);
        }
        return root;
    }
};
