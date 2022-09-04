/**
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. 
You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing 
the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string 
consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

Example 1:
Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* commonNode = commonAncestor(root, startValue, destValue);
        string p;
        string res;
        // find from commonNode to startValue
        tr(commonNode, startValue, p);
        res.resize(p.size());
        std::fill(res.begin(), res.end(), 'U');
        // find commonNode to destValue
        p.clear();
        tr(commonNode, destValue, p);
        for (int i = p.size()-1; i>=0; --i){
            res.push_back(p[i]);
        }
        return res;
    }
    
     bool tr(TreeNode* node, int target, string& p){
        if (node == nullptr){
            return false;
        }
        if (node->val == target){
            return true;
        }
        if (node->left!=nullptr){
            if (tr(node->left, target, p)){
                // find the node
                p.push_back('L');
                return true;
            }
        }
        if (node->right!=nullptr){
            if (tr(node->right, target, p)){
                // find the node
                p.push_back('R');
                return true;
            }
        }
         return false;
    }
    
    TreeNode* commonAncestor(TreeNode* root, int s, int d){
        if (root == nullptr){
            return nullptr;
        }
        // root is one node
        if (root->val == s || root->val == d){
            return root;
        }
        
        // iterate through children
        TreeNode* p = nullptr;
        TreeNode* q = nullptr;
        if (root->left!=nullptr){
            p = commonAncestor(root->left, s, d);
        }
        if (root->right!=nullptr){
            q = commonAncestor(root->right, s, d);
        }
        if (p == nullptr && q == nullptr){
            // nothing found
            return nullptr;
        }else if (p != nullptr && q!=nullptr){
            // start and destination node on two sides
            return root;
        }else{
            // p or q had node
            if (p!=nullptr){
                return p;
            }else{
                return q;
            }
        }
    }
};
