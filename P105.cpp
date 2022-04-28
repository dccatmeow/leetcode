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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Preorder 
        // [3,9,20,15,7]
        // [3,  9,  20,15,7]
        // root left right
        // Inorder
        // [9,3,15,20,7]
        // [9,  3,  15,20,7]
        // left root right
        return bt(preorder, inorder, 0, preorder.size()-1,0, inorder.size()-1);
    }
    
    TreeNode* bt(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
        if (inStart == inEnd){
            // only one element left
            return new TreeNode(inorder[inStart]);
        }
        if (inStart>inEnd){
            return nullptr;
        }
        auto root = new TreeNode(preorder[preStart]);
        int rootPos = std::find(inorder.begin(), inorder.end(), preorder[preStart])
            -inorder.begin();
        int leftN = rootPos - inStart;
        root->left = bt(preorder, inorder, preStart+1, preStart+leftN, inStart, rootPos-1); 
        root->right=bt(preorder, inorder, preStart+leftN+1, preEnd, rootPos+1, inEnd);
        return root;
    }
};
