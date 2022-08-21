/**
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively.
The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and 
ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int, multiset<pair<int, int>>> myMap;
    void dfs(TreeNode* root, int x, int y){
            if (root == nullptr) return;
            myMap[x].insert({y, root->val});
            dfs(root->left, x-1, y+1);
            dfs(root->right, x+1, y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, 0);
        
        for (auto& elem:myMap){
            vector<int> temp;
            for (auto i:elem.second){
                // i is iterator of type pair<int,int>
                temp.push_back(i.second);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};
