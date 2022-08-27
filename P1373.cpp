/**
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20

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
    int maxSumBST(TreeNode* root) {
        BST(root);
        return res;
    }
    
    vector<int> BST(TreeNode* root){
        // return the sum of BST, lowest value, highest value, isBST(0,1)
        // a flag to check BST
        bool flag = true;
        int minV = root->val;
        int maxV = root->val;
        int sum = root->val;
        // check if subtree are BST
        if (root->left!=nullptr){
            auto v1 = BST(root->left);
            if (v1[3] && root->val > v1[2]){
                minV = v1[1];
                sum+=v1[0];
            }else{
                flag = false;
            }
        }
        if (root->right!=nullptr){
            auto v2 = BST(root->right);
            if (v2[3] && root->val < v2[1]){
                maxV = v2[2];
                sum+=v2[0];
            }else{
                flag = false;
            }
        }
        if (flag){
            // BST
            res = max(res, sum);
            return vector<int>{sum, minV, maxV,1};
        }
        // not a BST
        return vector<int>{0, 0, 0, 0};
    }
    
private:
    int res;
};
