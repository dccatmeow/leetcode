class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort begin time and end time of meetings seperately
        // begin meeting ,add room 1
        // end meeting return room, minus room 1;
        int n = intervals.size();
        vector<int> startM(n,0);// allocate space for vector first
        vector<int> endM(n,0);
        int i=0;
        for (auto v:intervals){
            startM[i] = v[0]; // fill in vector
            endM[i] = v[1];
            ++i;
        }
        sort(startM.begin(), startM.end());
        sort(endM.begin(), endM.end());
        int res(0);
        int tmp(0);
        int j(0);
        i = 0;
        while(i!=n && j!=n){
            // add up room for started meeting til end of meeting
            if (startM[i]<endM[j]){
               tmp++;
                i++;
                res = max(res,tmp);
            }else{
                tmp--;
                j++;
            }
        }
        return res;
    }
};
