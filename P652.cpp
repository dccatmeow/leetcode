/**
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

Example 1:

Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

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
    unordered_map<string, int> m;
    vector<TreeNode*> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }
    
    string serialize(TreeNode* n){
        if (n==nullptr){
            return "#";
        }
        string l = serialize(n->left);
        string r = serialize(n->right);
        string tmp = l+"." +r+"."+to_string(n->val);
        if (m[tmp] == 1){
            res.push_back(n);
        }
        m[tmp]++;
        return tmp;
    }
};
// time complexity O(tree height)
// space complexity O(tree height)
