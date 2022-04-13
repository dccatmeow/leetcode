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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();
        ListNode* tmp = res;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val>list2->val){
                tmp->next = list2;
                list2 = list2->next;
            }else{
                tmp->next = list1;
                list1 = list1->next;
            }
            tmp = tmp->next;
        }
        if (list1 != nullptr){
            tmp->next = list1;
        }else if (list2 !=nullptr){
            tmp->next = list2;
        }
        return res->next;
    }
};
