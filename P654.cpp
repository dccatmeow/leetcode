/**
You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

Example 1:

Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return ct(nums, 0, nums.size()-1);
    }
    
    TreeNode* ct(vector<int>& nums, int s, int e){
        if (s==e){
            TreeNode* node = new TreeNode(nums[s]);
            return node;
        }
        // find max element between [s,e], [s,e+1)
        // max_element takes [first, end)
        auto it = max_element(nums.begin()+s, nums.begin()+e+1);
        int pos = it- nums.begin();
        
        TreeNode* root = new TreeNode(nums[pos]);
        if (pos == s){
            root->left = nullptr;
            root->right = ct(nums, s+1, e);
        }else if (pos == e){
            root->right = nullptr;
            root->left = ct(nums, s, e-1);
        }else{
            root->left = ct(nums, s, pos-1);
            root->right = ct(nums, pos+1, e);
        }
        return root;
    }
};
// time complexity O(logn)
// space complexity O(logn)
