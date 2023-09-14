/*
973. K Closest Points to Origin

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](vector<int>& v1, vector<int>& v2){
            int val1 = v1[0]*v1[0]+v1[1]*v1[1];
            int val2 = v2[0]*v2[0]+v2[1]*v2[1];
            return val1<val2;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        for (auto& v:points){
            pq.push(v);
            if (pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
