// 314. Binary Tree Vertical Order Traversal
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
    using pti = std::pair<TreeNode*,int>;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        queue<pti> q;
        q.push({root,0});
        while(!q.empty()){
            int n= q.size();
            while(n>0){
                auto [node,col] = q.front();
                q.pop();
                if (col>=0){
                    if (pos.size()<=col){
                        // new column
                        pos.push_back(vector<int>{node->val});
                    }else{
                        pos[col].push_back(node->val);
                    }
                }else{
                    if (neg.size()<=-col-1){
                        // new column
                        neg.push_back(vector<int>{node->val});
                    }else{
                        neg[-col-1].push_back(node->val);
                    }
                }
                if (node->left!=nullptr){
                    q.push({node->left, col-1});
                }
                if (node->right!=nullptr){
                    q.push({node->right, col+1});
                }
                n--;
            }
        }

        // combine pos, neg
        for (int i = neg.size()-1;i>=0;--i){
            res.push_back(std::move(neg[i]));
        }
        for (int i=0; i<pos.size(); ++i){
            res.push_back(std::move(pos[i]));
        }
        return res;
    }

private:
    vector<vector<int>> neg;
    vector<vector<int>> pos; // 0, ....
};
