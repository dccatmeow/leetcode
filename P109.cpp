**
109. Convert Sorted List to Binary Search Tree
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }
        if (head->next == nullptr){
            return new TreeNode(head->val);
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slowParent;
        // find the middle point of list
        // use this middle point as the root of the tree
        // slowParent  slow  slow->next
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slowParent = slow;
            slow = slow->next;
        }
        // break list into two part
        auto root = new TreeNode(slow->val);
        slowParent->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
