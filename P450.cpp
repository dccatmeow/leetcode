/**
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.

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
    TreeNode* res;
    TreeNode* deleteNode(TreeNode* root, int key) {
        // analyze based on different cases
        if (root == nullptr){
            return nullptr;
        }
        // find the key
        if (root->val == key){
            if (root->left == nullptr && root->right ==nullptr){
                return nullptr;
            }else if (root->left == nullptr && root->right !=nullptr){
                return root->right;
            }else if (root->right == nullptr && root->left != nullptr){
                return root->left;
            }else{
                // find sucessor of current node and move it to root, smallest number greater than root->val
                TreeNode* tmpP = root;
                TreeNode* tmp = root->right;
                // case 1:
                if (tmp->left == nullptr){
                    // tmp is the successor
                    tmp->left = root->left;
                    return tmp;
                }
                // case 2: find the tip tmp where tmp->left=nulltpr
                while(tmp->left!=nullptr){
                    tmpP = tmp;
                    tmp = tmp->left; // tmp is the sucessor
                }
                tmpP->left = tmp->right;
                tmp->left = root->left;
                tmp->right = root->right;
                return tmp;
            }
        }else if (root->val > key){
            root->left = deleteNode(root->left, key);
        }else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
    
};
