/**
86. Partition List

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l_new = new ListNode(0);
        ListNode* l = l_new;
        ListNode* h_new = new ListNode(0);
        ListNode* h = h_new;
        ListNode* tmp = head;
        while(tmp!=nullptr){
            if (tmp->val<x){
                l->next = tmp;
                l = l->next;
            }else{
                h->next = tmp;
                h=h->next;
            }
            tmp = tmp->next;
        }
        h->next = nullptr;
        l->next = h_new->next;
        return l_new->next;
    }
};
