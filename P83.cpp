
/**
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        int prevVal = head->val;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr!=nullptr){
            if (curr->val == prevVal){
                // do nothing
            }else{
                // connect prev to curr, update prev and prevVal
                prev->next = curr;
                prev = prev->next;
                prevVal = curr->val;
            }
            curr = curr->next;
        }
        // remove the duplicates for the same value as prev
        // e.g. [1,2,2,2,2]
        prev->next = nullptr;
        return head;
    }
};
