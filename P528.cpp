/*
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. 
The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), 
and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).

*/

class Solution {
public:
    Solution(vector<int>& w) {
        int n = w.size();
        data.resize(n);
        // data is the presum of w
        data[0]=w[0];
        for (int i=1; i<n; i++){
            data[i] = data[i-1]+w[i];
        }
        maxV = data[n-1];
    }
    
    int pickIndex() {
        auto it = lower_bound(data.begin(), data.end(), rand()%maxV+1);
        return it-data.begin();
    }
private:
    vector<int> data;
    int maxV;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
