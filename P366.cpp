/*
Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
*/

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        // initialize with an empty vector
        res.push_back(vector<int>());
        dfs(root);
        return res;
    }
    
    int dfs(TreeNode* root){
        // the most leaf node has distance 0
        // the parent of most leaf node has distance 1
        // ....
        if (root->left == nullptr && root->right== nullptr){
            // leaf node
            res[0].push_back(root->val);
            return 0;
        }
        int l(0), r(0);
        if (root->left!=nullptr){
            l = dfs(root->left);
        }
        if (root->right!=nullptr){
            r = dfs(root->right);
        }
        int idx = max(l,r)+1;
        if (res.size()-1<idx){
            // push back a new vector to expand res
            res.push_back(vector<int>());
        }
        res[idx].push_back(root->val);
        return idx;
        
    }
private:
    vector<vector<int>> res;
};
