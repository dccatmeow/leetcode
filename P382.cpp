/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:

Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.
 

Example 1:


Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

*/

class Solution {
public:
    // the probability of selecting i is 1/i
    // the probability of not selecting i+1 is 1-1/i+1
    // in the end select i is P = 1/i * (1-1/(i+1))*... = 1/n
    // for current node just pick 1/i is good to realize overall probability
    
    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        int res(0);
        int count(1);
        ListNode* c = h;
        while(c!=nullptr){
            if ((rand())%count == 0){
                // find the one
                res = c->val;
            }
            c = c->next;
            count++;
        }
        return res;
    }
private:
    ListNode* h;
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
