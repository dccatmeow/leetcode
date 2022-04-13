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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // k1....k2 k3....k4
        // k2....k1 k3....k4
        // .........k1....k2 k3...
        ListNode* k1 = head;
        ListNode* res = reverseK(k1, k-1);
        while(k3!=nullptr){
            // ...prev k1...k2 k3...
            // ...prev k2...k1 k3...
            ListNode* prev = k1;
            k1 = k3;
            ListNode* k2 = reverseK(k1, k-1);
            if (k2 != nullptr){
                prev->next = k2;
            }
            
        }
        return res;
    }
    
    ListNode* reverseK(ListNode* head, int k){
        // reverse first k of list node head
        if (head == nullptr){
            k3 = nullptr;
            return head;
        }else if (k==0){
            // store the next pointer to a global var
            // this var is the starting of next section
            k3 = head->next;
            return head;
        }else if (head->next == nullptr && k>0){
            // this session is not long enough
            k3 = nullptr;
            return nullptr;
        }else{
            // recursive call
            // head->l1->l2->l3
            // head->l1<-l2<-l3
            // head->l1<-l2<-l3
            //     |<-
            ListNode* k2 = reverseK(head->next, k-1);
            if (k2!=nullptr){
                head->next->next = head;
                head->next = k3;
            }
            return k2;
        }
    }
private:
    ListNode* k3;
};
