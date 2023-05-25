

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

// DFS to traverse and create a memory for fast checking. data structure is important
// at each level, loop through all the nodes and find the max.
class Solution {
    using pii = pair<int,int>;
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> res;
        // set all the depth from current to end
        traverse(root, 0);
        // sort by height for each level
        for (auto& elem:level){
            sort(elem.second.begin(), elem.second.end(), greater());
        }

        for (auto i:queries){
            auto lv = m[i];
            int tmp = lv-1;// for i the height is level-1
            for (int j=0; j<level[lv].size(); ++j){
                auto [h, e] = level[lv][j];
                if (e!=i){
                    tmp = max(tmp, h+lv);
                }else{
                    // check one more pair before jump out
                    if (j<level[lv].size()-1){
                        j++;
                        auto [h,e] = level[lv][j];
                        tmp = max(tmp, h+lv);
                        break;
                    }
                }
            }
            res.push_back(tmp);
        }
        return res;
    }

    int traverse(TreeNode* node, int lv){
        if (node == nullptr){
            // tree leaf
            return -1;
        }else{
            // traverse children tree
            int h = 1+max(traverse(node->left, lv+1), traverse(node->right, lv+1));
            m[node->val] = lv;
            level[lv].push_back(pii(h, node->val));
            return h;
        }
    }

private:
    // key TreeNode->val, pii(level from root to node)
    unordered_map<int,int> m;
    // level[0] = pii(height,root), level[1]= root->left, root->right
    unordered_map<int, vector<pii>> level;
};
