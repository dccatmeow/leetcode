/*
1650. Lowest Common Ancestor of a Binary Tree III

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
/*
starting from p to root is x
starting from q to root is y
starting from LCA to root is z
when node reach root, restart from the other node, x+(y-z) == y+(x-z)
they will meet at LCA.
*/
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* a=p;
        Node* b=q;
        while(a!=b){
            if (a!=nullptr){
                // p is left branch
                a = a->parent;
            }else{
                // reach the root
                a = q;
            }
            if (b!=nullptr){
                b = b->parent;
            }else{
                // reach the root
                b = p;
            }
        }
        return a;
        
    }
};
