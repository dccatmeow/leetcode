/*
Given the head of a singly linked list, return true if it is a palindrome.
**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // left is the one moving from head to the end
    // n is the one coming from end to head
    // traverse function will keep digging until nullptr
    // then the first comparison is between n=last element and head
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(left);
    }
    
    bool traverse(ListNode* n){
        if (n == nullptr){
            return true;
        }
        if (traverse(n->next)){
            if (n->val == left->val){
                // only true path, move to next comparison
                left = left->next;
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};
// time complexity O(n)
// space complexity O(1)
