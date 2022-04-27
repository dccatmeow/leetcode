/**
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool isSymmetric(TreeNode* root) {
      // recursive call back check left and right part symmetrically
        return isEqual(root->left, root->right);
    }
    
    bool isEqual(TreeNode* left, TreeNode* right){
        if (left ==nullptr && right == nullptr){
            return true;
        }
        if (left!=nullptr && right!=nullptr && left->val == right->val){
            // check two sides
            return isEqual(left->left, right->right) && isEqual(left->right, right->left);
        }
        return false;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // use queue to do a iterative traverse tree
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            if (t1 == nullptr && t2 == nullptr){
                continue;
            }else if (t1 == nullptr || t2 == nullptr){
                return false;
            }else if (t1->val != t2->val){
                return false;
            }else{
                q.push(t1->left);
                q.push(t2->right);
                q.push(t1->right);
                q.push(t2->left);
            }
        }
        return true;
    }
};
