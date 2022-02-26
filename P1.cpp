/* 111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.


*/
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
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        return bt(root);
    }
    
    int bt(TreeNode* root){
        if (root->left == nullptr && root->right == nullptr){
            return count;
        }
        count++;
        int l(INT_MAX),r(INT_MAX);
        if (root->left!=nullptr){
            l = bt(root->left);
        }
        if (root->right!=nullptr){
            r = bt(root->right);
        }
        count--;
        return min(l, r);
    }
private:
    int count = 1;
};

// second method BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
      if (root == nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        int res = 0;
        while(!q.empty()){
            // add level
            ++res;
            // exercise all the neighbour in the same level
            int size = q.size();
            for (size_t i=0; i<size;++i){
                temp = q.front();
                if (temp->left!=nullptr){
                    q.push(temp->left);
                }
                if (temp->right!=nullptr){
                    q.push(temp->right);
                }
                if (temp->left == nullptr && temp->right == nullptr){
                    // find the shortest path
                    return res;
                }
                q.pop();
            }
            
        }
        
        return res;
    }
};
// BFS time complexity O(n)
// space complexity O(n) the bottom of the tree node n/2
