/**
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int c(n);
        while(tmp!=nullptr && n>0){
            tmp = tmp->next;
            n--;
        }
        // list is not long enough to hold n element
        if (n!=0){
            return nullptr;
        }
        // if tmp reach the end of list then remove head
        if (tmp == nullptr){
            return head->next;
        }
        // double pointer move until fast one reach the end of list
        ListNode* res = head;
        // move tmp ahead once, so res should remove its next pointer
        tmp = tmp->next;
        while(tmp!=nullptr){
            tmp = tmp->next;
            res = res->next;
        }
        // remove res->next
        tmp = res->next->next;
        res->next = tmp;
        return head;
    }
};
