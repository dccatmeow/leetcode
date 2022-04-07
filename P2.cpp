/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry(0);
        ListNode* resF = new ListNode();
        ListNode* res = resF;
        while(l1!=nullptr && l2!=nullptr){
            int tmp = l1->val+l2->val+carry;
            // update carry;
            carry = tmp/10;
            ListNode* tmpN = new ListNode(tmp%10);
            res->next = tmpN;
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* tmpN;
        if (l1 == nullptr){
            // l2 exist
            l1 = l2;
        }
        while(l1!=nullptr){
            int tmp = l1->val+carry;
            // update carry;
            carry = tmp/10;
            ListNode* tmpN = new ListNode(tmp%10);
            res->next = tmpN;
            res = res->next;
            l1 = l1->next;
        }
        if (carry!=0){
            ListNode* tmpN = new ListNode(carry);
            res->next = tmpN;
        }
        
        return resF->next;
    }
};
