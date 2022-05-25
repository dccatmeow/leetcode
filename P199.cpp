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
    void recursive(TreeNode* root, int level, vector<int>& res){
        if(root==NULL){
            return;
        }
        if(level>res.size()){
            // after looping through most right branches, this check makes sure that right branch of left children only save to res if there is no most right branch in the existing result.
            res.push_back(root->val);
        }
        // check most right branches first, this avoid other element pushed into res on the same level
        recursive(root->right, level+1, res);
        recursive(root->left, level+1, res);
        
        
    }
        
    vector<int> rightSideView(TreeNode* root) {
        // construct tree 
        vector<int> res;
        recursive(root, 1, res);
        return res;
    }
};
