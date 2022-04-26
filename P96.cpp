/*Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:
Input: n = 3
Output: 5
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> mem(n+1, 0);
        mem[0] = 1;// use 1 to enable multiplication
        mem[1] = 1;
        // 3's children are 0+2, 1+1, 2+0
        // mem[3] = mem[0]*mem[2] + mem[1]*mem[1] + mem[2]*mem[0]
        for (int i=2; i<=n; ++i){
            int tmp=0;
            for (int root=1; root<=i; root++){
                // loop through all the possible root
                tmp+=mem[root-1]*mem[i-root];
            }
            mem[i] = tmp;
        }
        return mem[n];
    }
};
