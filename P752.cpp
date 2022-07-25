/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.
The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. 
Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes,
the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, 
return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000"){
            return 0;
        }
        // save deadend in hash table
        unordered_set<string> dd(deadends.begin(), deadends.end());
        if (dd.count(target) || dd.count("0000")){ // initial condition ***
            return -1;
        }
        queue<string> q;
        q.push("0000");
        int res = -1;
        unordered_set<string> visited; // visited to reduce time ***
        visited.insert("0000");
        
        while (!q.empty()){
            res++;
            size_t len = q.size();
            for (size_t i=0; i<len;i++){
                string temp = q.front();
                q.pop();
                if (temp == target){
                    return res;
                }
                getNextMove(q, temp, dd, visited);
            }
        }
        return -1;
        
    }
    
    void getNextMove(queue<string>& q, const string temp, const unordered_set<string>& dd, unordered_set<string>& visited ){
        for (int i=0; i<4; ++i){
            string s = temp;
            // move one wheel one slot forward
            s[i] = (s[i]-'0'+1)%10 +'0';
            if (!dd.count(s) && !visited.count(s)){
                // valid case, not in dd and not visited
                q.push(s);
                visited.insert(s);
            }
            s = temp;
            // move one wheel one slot backward
            s[i] = (s[i]-'0'+9)%10 +'0'; // calculate -1 using +9 ***
            if (!dd.count(s) && !visited.count(s)){
                // valid case not in dd and not visited
                q.push(s);
                visited.insert(s);
            }
        }
    }
};
// worst scenario loop through all the possible solution
// bfs time complexity O(4^9)
// bfs space complexity O(4^9)
