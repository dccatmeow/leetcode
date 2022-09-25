/*
You are given an integer array arr. From some starting index, you can make a series of jumps. The (1st, 3rd, 5th, ...) 
jumps in the series are called odd-numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even-numbered jumps. 
Note that the jumps are numbered, not the indices.

You may jump forward from index i to index j (with i < j) in the following way:

During odd-numbered jumps (i.e., jumps 1, 3, 5, ...), you jump to the index j such that arr[i] <= arr[j] and arr[j] is the smallest possible value. 
If there are multiple such indices j, you can only jump to the smallest such index j.
During even-numbered jumps (i.e., jumps 2, 4, 6, ...), you jump to the index j such that arr[i] >= arr[j] and arr[j] is the largest possible value. 
If there are multiple such indices j, you can only jump to the smallest such index j.
It may be the case that for some index i, there are no legal jumps.
A starting index is good if, starting from that index, you can reach the end of the array (index arr.length - 1) by jumping some number of times 
(possibly 0 or more than once).

Return the number of good starting indices.

Example 1:

Input: arr = [10,13,12,14,15]
Output: 2
*/

class Solution {
public:
    using pbb = std::pair<bool, bool>;
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        int res(0);
        // value, position
        map<int, int> m; 
        // pbb is from this point, next move is odd jump and even jump
        // if odd jump can reach last element, first value is true
        // if even jump can reach last element, second value is true
        vector<pbb> dp(n, pbb(false,false));
        dp[n-1] = pbb(true, true);
        res++;
        m[arr[n-1]] = n-1;
        for (int i=n-2; i>=0; --i){
            bool tmp(false);
            bool tmp1(false);
            // if from i next move is odd jump
            // smallest value greater than arr[i]
            auto it = m.lower_bound(arr[i]);
            if (it!=m.end()){
                // find the next next even jump
                tmp = dp[it->second].second;
            }
            
            // if from i next move is even jump
            // largest value smaller than arr[i]
            it = m.upper_bound(arr[i]);
            if (it!=m.begin()){
                it--;
                // next next odd jump
                tmp1 = dp[it->second].first;
            }
            m[arr[i]] = i;
            dp[i] = pbb(tmp, tmp1);
            // starting from current node is always 1, odd move
            if (tmp){
                res++;
            }
        }
        return res;
    }
};
