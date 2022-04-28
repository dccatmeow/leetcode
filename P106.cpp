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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Inorder
        // [9,3,15,20,7]
        // [9,  3,  15,20,7]
        // left root right
        // Postorder
        // [9,15,7,20,3]
        // [9,   15,7,20   ,3]
        // left  right    root
        return bt(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode* bt(vector<int>& inorder, vector<int>& postorder, 
                 int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart == inEnd){
            return new TreeNode(inorder[inStart]);
        }
        if (inStart > inEnd){
            return nullptr;
        }
        auto root = new TreeNode(postorder[postEnd]);
        auto rootPos = std::find(inorder.begin(), inorder.end(), postorder[postEnd])
            -inorder.begin();
        int rightLen = inEnd - rootPos;
        root->right = bt(inorder, postorder, rootPos+1, inEnd, postEnd-rightLen, postEnd-1);
        root->left = bt(inorder, postorder, inStart, rootPos-1,  postStart, postEnd-rightLen-1);
        return root;
    }
};
