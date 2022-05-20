/**
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.
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
    ListNode* insertionSortList(ListNode* head) {
        // add a dummy node
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* pre=dummy;
        ListNode* curr=dummy->next;
        while(curr){
            // sorted til pre, insert curr node
            if (pre->val > curr->val){
                // isolate curr;
                pre->next = curr->next;
                curr->next = nullptr;
                // find the correct place for curr
                ListNode* tmp_pre = dummy;
                ListNode* tmp = tmp_pre->next;
                while(tmp->val<curr->val){
                    tmp_pre = tmp;
                    tmp = tmp->next;
                }
                tmp_pre->next = curr;
                curr->next = tmp;
                // move to next position
                curr = pre->next;
                
            }else{
                pre = curr;
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};
