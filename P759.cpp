/*
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. 
For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  
Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]

// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    using pii = std::pair<int,int>;
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        // iterate throught schedule
        auto comp = [&schedule](pii& p1, pii& p2){
            return schedule[p1.first][p1.second].start > schedule[p2.first][p2.second].start;
        };
        // pii {i, j}
        priority_queue<pii, vector<pii>, decltype(comp)> q(comp);
        for (int i=0; i<schedule.size(); ++i){
            // push first element on each row into the queue
            q.push({i, 0});
        }
        // initialize tmp with start of first work time
        auto [i, j] = q.top();
        int tmp = schedule[i][j].start;
        vector<Interval> res;
        while(!q.empty()){
            // s, e, i ,j
            auto [i,j] = q.top();
            q.pop();
            // check if tmp and s have a gap
            // tmp  s  e
            if (tmp<schedule[i][j].start){
                res.push_back(Interval(tmp, schedule[i][j].start));
            }
            // update tmp to farest end
            tmp = max(tmp,schedule[i][j].end);
            // push next element in the same row into priority queue
            if (j!=schedule[i].size()-1){
                j++;
                q.push(pii(i,j));
            }
        }
        return res;
    }
};
