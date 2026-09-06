/**
199. Binary Tree Right Side View
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
    vector<int> result;

    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }

        // First node we encounter at this depth
        if (depth == result.size()) {
            result.push_back(node->val);
        }

        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)
