/**
103. Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==nullptr){
            return res;
        }
        vector<TreeNode*> tmp;
        vector<int> tmpV;
        int cnt=1;
        tmp.push_back(root);
        tmpV.push_back(root->val);
        res.push_back(tmpV);
        cnt++;
        while(!tmp.empty()){
            vector<TreeNode*> newTmp;
            tmpV.clear();
            for (auto e:tmp){
                if (e->left!=nullptr){
                    newTmp.push_back(e->left);
                    tmpV.push_back(e->left->val);
                }
                if(e->right!=nullptr){
                    newTmp.push_back(e->right);
                    tmpV.push_back(e->right->val);
                }
            }
            if (!tmpV.empty()){
                if (cnt%2 == 0){
                    reverse(tmpV.begin(),tmpV.end());
                }
                res.push_back(tmpV);
            }
            
            cnt++;
            tmp = newTmp;
        }
        return res;
    }
    
private:
    vector<vector<int>> res;
};
