

/**

2458. Height of Binary Tree After Subtree Removal Queries

You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:

Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

Note:

The queries are independent, so the tree returns to its initial state after each query.
The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
 

Example 1:


Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
Output: [2]
Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -> 3 -> 2).

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
    using pii = pair<int,int>;
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        maxh = 0;
        preTrav(root, 0);
        maxh = 0;
        postTrav(root,0);
        vector<int> res;
        for (int q:queries){
            res.push_back(max(preh[q], posth[q]));
        }
        return res;
    }

    void preTrav(TreeNode* node, int h){
        if (!node){
            return;
        }
        preh[node->val] = maxh;
        maxh = max(maxh,h);
        preTrav(node->left, h+1);
        preTrav(node->right, h+1);
    }
    void postTrav(TreeNode* node, int h){
        if (!node){
            return;
        }
        
        posth[node->val] = maxh;
        maxh = max(maxh,h);
        postTrav(node->right, h+1);
        postTrav(node->left, h+1);
    }

private:
    int maxh;
    int preh[100001], posth[100001];
};
