/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // calculate presum and postsum from 0,...k-1
        // n-1-k+1,...n-1
        vector<int> presum(k+1,0);
        vector<int> postsum(k+1,0);
        int n = cardPoints.size();
        for (int i=1; i<=k; ++i){
            presum[i] = presum[i-1]+cardPoints[i-1];
            postsum[i] = postsum[i-1]+cardPoints[n-i];
        }
        int res(0);
        // calculate the combination
        // presum[0] means no element in front
        for(int i=0; i<=k; ++i){
            res = max(res, presum[i]+postsum[k-i]);
        }
        return res;
    }
};
