/*
1762. Buildings With an Ocean View
There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.
*/

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> stk;
        stk.push(0);
        for (int i=1; i<heights.size(); ++i){
            while (heights[i]>=heights[stk.top()]){
                stk.pop();
                if (stk.empty()){
                    break;
                }
            }
            stk.push(i);
        }
        int n=stk.size();
        vector<int> res(n,0);
        while(n>0){
            res[n-1] = stk.top();
            stk.pop();
            n--;
        }
        return res;
    }
};
