/*
    bool comp(vector<int>& v1, vector<int>& v2){
        if (v1[0] == v2[0]){
            // second element from largest to smallest
            return v1[1] > v2[1];
        }
        // first element from smallest to largest
        return v1[0] < v2[0];
    }
class Solution {
public:
    // try [[1,6],[2,8],[3,7],[3,2],[4,8]]
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sorted from small to large for first element
        // sorted from large to small for second element
        // so for second element smaller one can override large one
        sort(envelopes.begin(), envelopes.end(), comp);
        // res store second element of valid envelop
        // the actual value is not important, the size is important
        vector<int> res;
        for (auto elem: envelopes){
            // find the very first element in res that is greater or equal to elem[1]
            auto it = lower_bound(res.begin(), res.end(), elem[1]);
            if (it == res.end()){
                // larger element
                // because of ealier sorting, this element is definitely the largest
                // when for same size of elevelop first element 
                res.push_back(elem[1]);
            }else{
                // if existing element in res is equal to elem[1]
                // it does not qualify add a new envelop, keep updating
                // if existing elment in res is greater than elem[1]
                // update res using elem[1]
                *it = elem[1];
            }
        }
        return res.size();
    }
};
// time complexity O(nlogn)
*/
