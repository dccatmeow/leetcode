/**
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //A+B
    //B+A
    // the intersection is at the first met point at second B and second A
    // if no intersection, then it meet at the end with two nullptr
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* f = headA;
        ListNode* s = headB;
        while(f!=s){
            if (f==nullptr){
                f = headB;
            }else{
                f = f->next;
            }
            if(s == nullptr){
                s = headA;
            }else{
                s = s->next;
            }
        }
        return f;
    }
};
// time complexity (O(element in A+element in B))
// space complexity O(1)
