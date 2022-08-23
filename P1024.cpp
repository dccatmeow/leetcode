/*
You are given a series of video clips from a sporting event that lasted time seconds. 
These video clips can be overlapping with each other and have varying lengths.

Each video clip is described by an array clips where clips[i] = [starti, endi] indicates that the ith clip started at starti 
and ended at endi.

We can cut these clips into segments freely.

For example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event [0, time]. 
If the task is impossible, return -1.

Example 1:

Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], time = 10
Output: 3
*/

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // sort by begin time from small to large
        // if begin time is same, sort by end time from large to small
        // The larger second element is the better
        auto comp = [](vector<int>& v1, vector<int>& v2){
            if (v1[0] == v2[0]){
                return v1[1]>v2[1];
            }else{
                return v1[0]<v2[0];
            }
        };
        sort(clips.begin(), clips.end(), comp);
        // check first begin time
        if (clips[0][0]!=0){
            return -1;
        }
        // vector<int> prev(2,-1); // {-1,-1}
        int res(1);
        vector<int> prev = clips[0];
        vector<int> tmp = clips[0]; // store the local optimal
        for (auto v:clips){
            if (v == clips[0]){
                // first element
                continue;
            }
            if (prev[1] >= time){
                // find solution
                return res;
            }
            if (v[0]<=prev[1] && v[1]>tmp[1]){
                // prev[0]       prev[1]
                //          tmp[0]  tmp[1]
                //           v[0]            v[1]
                // v is better than tmp, goes farer
                // v is overlapping prev, valid
                tmp = v;
            }else if (v[0] > prev[1] && tmp[1]<v[0]){
                // prev[0]   prev[1] 
                //       tmp[0] tmp[1]
                //                       v[0]  v[1]
                return -1;
            }else if (v[0] > prev[1] && tmp[1]>=v[0]){
                // prev[0]   prev[1] 
                //       tmp[0]    tmp[1]
                //                  v[0]  v[1]
                res++;
                prev = tmp;
                tmp = v;
            }
        }
        // check last element
        if (prev[1]>=time){
            return res;
        }else{
            if (tmp[1]>=time){
                return res+1;
            }
        }
        return -1;
    }
};
