/**
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
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
    int countNodes(TreeNode* root) {
        if (root==nullptr){
            return 0;
        }
      // find the subtree and see if they are full tree
      // for full tree calculate based on geometric sequence
        int lc = 1; 
        int rc = 1;
        auto tmp = root;
        while(tmp->left!= nullptr){
            tmp = tmp->left;
            lc++;
        }
        tmp = root;
        while(tmp->right != nullptr){
            tmp = tmp->right;
            rc++;
        }
        if (lc > 1 && lc == rc){
            return pow(2, lc)-1; // a1(1-q^n)/(1-q) 
        }
        
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left+right+1;
    }
};
// time complexity O(logn*logn), each node has logn time to find and there are logn level
// space complexityO(1)
