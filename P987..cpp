/**
987. Vertical Order Traversal of a Binary Tree

Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.


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
    using pii = std::pair<int,int>; // row, value
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        queue<pti> q;
        q.push({root,0});
        int row = 0;
        while(!q.empty()){
            int n= q.size();
            while(n>0){
                auto [node,col] = q.front();
                q.pop();
                if (col>=0){
                    if (pos.size()<=col){
                        // new column
                        pos.push_back(vector<pii>{pii(row,node->val)});
                    }else{
                        pos[col].push_back(pii(row,node->val));
                    }
                }else{
                    if (neg.size()<=-col-1){
                        // new column
                        neg.push_back(vector<pii>{pii(row,node->val)});
                    }else{
                        neg[-col-1].push_back(pii(row,node->val));
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
            row++;
        }

        // combine pos, neg
        auto comp = [](auto p1, auto p2){
            if (p1.first==p2.first){
                return p1.second<p2.second;
            }
            return p1.first<p2.first;
        };
        for (int i = neg.size()-1;i>=0;--i){
            auto v = std::move(neg[i]);
            sort(v.begin(), v.end(), comp);
            vector<int> tmp(v.size(),0);
            for (int j=0;j<v.size();++j){
                tmp[j] = v[j].second;
            }
            res.push_back(std::move(tmp));
        }
        for (int i=0; i<pos.size(); ++i){
            auto v = std::move(pos[i]);
            sort(v.begin(), v.end(), comp);
            vector<int> tmp(v.size(),0);
            for (int j=0;j<v.size();++j){
                tmp[j] = v[j].second;
            }
            res.push_back(std::move(tmp));
        }
        return res;
    }

private:
    vector<vector<pii>> neg;
    vector<vector<pii>> pos; // 0, ....
};
