2402. Meeting Rooms III
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

 

Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0



class Solution {
public:
// because we need to keep track of available meeting room and end of current meetings
// there is constantly checking for available room and meeting ended now
// two heap, priority queue is needed to track this

using pli = std::pair<long long,int>;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        auto comp = [](vector<int>& v1, vector<int>& v2){
            return v1[0]<v2[0];
        };
        sort(meetings.begin(), meetings.end(), comp);
        // current meetings queue pli end time and room number
        priority_queue<pli, vector<pli>, greater<pli>> endQ;
        priority_queue<int, vector<int>, greater<int>> roomQ;
        vector<int> room(n,0); // store count of meetings held in the room
        for (int i=0; i<n; ++i){
            roomQ.push(i);
        }
        for (auto elem:meetings){
            // update endQ, roomQ
            while(!endQ.empty() && endQ.top().first<=elem[0]){
                // end meetings update
                roomQ.push(endQ.top().second);
                endQ.pop();
            }
            // add meeting to endQ
            if (!roomQ.empty()){
                endQ.push(pli(elem[1],roomQ.top()));
                room[roomQ.top()]++;
                roomQ.pop();
            }else{
                // delay current meeting till there is available room
                auto newEndTime = endQ.top().first+elem[1]-elem[0];
                endQ.push(pli(newEndTime, endQ.top().second));
                room[endQ.top().second]++;
                endQ.pop();
            }
        }
        int res(0);
        for (int i=0; i<n; ++i){
            if (room[i]>room[res]){
                res = i;
            }
        }
        return res;
    }
};
