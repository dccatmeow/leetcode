/*773. Sliding Puzzle

On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

 

Example 1:


Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Example 2:


Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Example 3:


Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
 

Constraints:

board.length == 2
board[i].length == 3
0 <= board[i][j] <= 5
Each value board[i][j] is unique.
*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // init size is 6
        string init;
        for (int i=0; i<2; ++i){
            for (int j=0; j<3; ++j){
                init.push_back(board[i][j]+'0');
            }
        }
        unordered_map<string, bool> visited;
        // this is the possible next step of 0
        // when it is at location 0, it can only go to 1 (right) or 3 (down)
        vector<vector<int>> next{
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };
        string target = "123450";
        queue<string> q;
        q.push(init);
        int count(0);
        while(!q.empty()){
            int n=q.size();
            for (int i=0; i<n; ++i){
                string e = q.front();
                q.pop();
                if (e == target){
                    return count;
                }
                if (!visited.count(e)){
                    // not visited
                    int loc = e.find_first_of('0');
                    for(auto pos:next[loc]){
                        auto tmp = e;
                        char tmpc = tmp[loc];
                        tmp[loc] = tmp[pos];
                        tmp[pos] = tmpc;
                        q.push(tmp);
                    }
                    visited[e] = true;
                }
            }
            count++;
        }
        return -1;
    }
};
