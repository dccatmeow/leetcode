/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
*/
/**
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // lnodeP, lnode, rnode, rnodeC
        // lnodeP, rnode, lnode, rnodeC
        // use a dummy node befor head
        ListNode* lnodeP = new ListNode(-501, head);
        ListNode* res = lnodeP;
        int count(0);
        // find node at left position
        while(lnodeP!=nullptr && count<left-1){
            lnodeP = lnodeP->next;
            count++;
        }
        // check if no need to reverse
        if (lnodeP ==nullptr || lnodeP->next == nullptr){
            return head;
        }
        ListNode* lnode = lnodeP->next;
        ListNode* rnode = reverseK(lnode, ++count, right);
        lnodeP->next = rnode;
        if (rnodeC->val!=-501){
            // exist rnodeC
            lnode->next = rnodeC;
        }
        return res->next;
    }
    
    ListNode* reverseK(ListNode* tmp, int count, int right){
        if (tmp->next == nullptr){
            // no rnodeC
            return tmp;
        }
        if (count == right){
            // node at position right
            rnodeC = tmp->next;
            return tmp;
        }
        ListNode* rnode = reverseK(tmp->next, ++count, right);
        tmp->next->next = tmp;
        tmp->next = nullptr;
        return rnode;
    }
private:
    ListNode* rnodeC = new ListNode(-501);
};
