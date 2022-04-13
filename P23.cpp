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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return nullptr;
        }
        auto comparator = [](ListNode* l, ListNode* r){return l->val > r->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> q(comparator);
        ListNode res;
        ListNode* tmp = &res;
        for(auto i:lists){
            if (i!=nullptr){
                q.push(i);
            }
        }
        while(!q.empty()){
            tmp->next = q.top();
            q.pop();
            tmp = tmp->next;
            // push in new node
            if (tmp->next != nullptr){
                q.push(tmp->next);
            }
        }
        return res.next;
    }
};

// time complexity O(elements in lists)
// space complexity O(log(elements in lists))
