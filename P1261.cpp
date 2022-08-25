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
/*
Given a binary tree with the following rules:

root.val == 0
If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.

*/
class FindElements {
public:
    
    FindElements(TreeNode* root) {
        root->val = 0;
        setData(root);
    }
    
    void setData (TreeNode* root){
        data.insert(root->val);
        // set left
        if (root->left){
            root->left->val = 2*root->val+1;
            setData(root->left);
        }
        // set right
        if (root->right){
            root->right->val = 2*root->val+2;
            setData(root->right);
        }
        return;
    }
    
    bool find(int target) {
        return data.count(target);
    }
private: 
    unordered_set<int> data;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
