/**
968. Binary Tree Cameras
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:

Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

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
    int minCameraCover(TreeNode* root) {
        res = 0;
        int tmp = dfs(root);
        if (tmp == 0){
            res++;
        }
        return res;
    }
    // 0 is not covered
    // 1 is camera
    // 2 is nullptr or node that is covered, no camera
    int dfs(TreeNode* node){
        if (node == nullptr){
            return 2;
        }
        int l = dfs(node->left);
        int r = dfs(node->right);
        if (l==0 || r==0){
            res++;
            return 1;
        }
        if (l==1||r==1){
            return 2;
        }
        return 0;
    }
private:
    int res;
};
