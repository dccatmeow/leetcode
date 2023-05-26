/**
1110. Delete Nodes And Return Forest

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

Example 1:


Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto i:to_delete){
            del.insert(i);
        }
        traverse(root, true, nullptr);
        return res;
    }

    void traverse(TreeNode* node, bool newRoot, TreeNode* parent){
        if (node == nullptr){
            return;
        }
        if (del.find(node->val)==del.end()){
            if (newRoot){
                res.push_back(node);
            }
            if (node->left){
                traverse(node->left, false, node);
            }
            if (node->right){
                traverse(node->right, false, node);
            }
        }else{
        // node can be removed from current tree
        // and its children can create a new root
            if (node->left){
                traverse(node->left, true, nullptr);
            }
            if (node->right){
                traverse(node->right, true, nullptr);
            }
            if (parent && parent->left && parent->left == node){
                parent->left = nullptr;
            }else if (parent && parent->right && parent->right == node){
                parent->right = nullptr;
            }
        }
    }
private:
    vector<TreeNode*> res;
    unordered_set<int> del;
};
