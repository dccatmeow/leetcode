/*
Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.
*/

class Solution {
public:
    void layBlock(vector<int>& skyline, int m, int n, int count, int& res , int left, int right){
        // make sure we are not exceed the ceiling
        right = min(right-left+1, n-skyline[left]) + left -1;
        
        // loop through all the possible squares between left and right in lowest level of skyline
        for (int idx = left; idx <= right; ++idx){
            // pick block [left, idx]
            ++count;
            // check if it exceed res
            if (count >= res) {
                return;
            }
            
            // add block to skyline
            for (int i = left; i <= idx; ++i){
                skyline[i] += idx-left+1;   
            }
            
            // find new left and right of lowest level of skyline
            int tempLeft = 0;
            for (int i = 1; i < m; ++i){         
                // find first minimum value and assign to tempLeft
                if (skyline[i] < skyline[tempLeft]){
                    tempLeft = i;
                }
            }
            int tempRight = tempLeft;
            for (int i = tempLeft+1; i < m; ++i){
                if (skyline[i] == skyline[tempLeft]){
                    tempRight = i;
                }else{
                    break;
                }
            }

            // check if rectangular is filled up
            if (skyline[tempLeft] == n){
                res = min(res, count);
            } else {
                // call layBlock to fill in another square
                layBlock(skyline, m, n, count, res, tempLeft, tempRight);
            }
            
            // remove block from skyline
            --count;
            for (int i = left; i <= idx; ++i){
                skyline[i] -= idx-left+1;   
            }
        }
    }
    
    int findMaxBound(int n, int m){
        int maxBound = 0;
        while(!(m==0 || n==0)){
            if (m<n){
                swap(m, n);
            }
            m = m-n;
            ++maxBound;
        }
        return maxBound;
    }
        
    int tilingRectangle(int n, int m) {
        // initialize skyline vector
        vector<int> skyline(m, 0);
        int res = 0;
        // find a maximum bound for result
        // if m and n are adjacent in fibonacci sequence maxBound is the result
        res = findMaxBound(n, m);
        layBlock(skyline, m, n, 0, res, 0, m-1);
        return res;
    }
};
