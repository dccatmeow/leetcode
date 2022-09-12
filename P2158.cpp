/*
There is a long and thin painting that can be represented by a number line. You are given a 0-indexed 2D integer array paint of length n,
where paint[i] = [starti, endi]. This means that on the ith day you need to paint the area between starti and endi.

Painting the same area multiple times will create an uneven painting so you only want to paint each area of the painting at most once.

Return an integer array worklog of length n, where worklog[i] is the amount of new area that you painted on the ith day.
*/

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        // use map to store painted gap [begin,end]
        // m[begin] = end
        map<int,int> m;
        m[-2]=-1; // boundary for while loop
        m[-1] = 0;
        vector<int> res;
        for (auto v:paint){
            // get painted slots
            int i=0;// i is overlapped painted area
            
            auto it = m.lower_bound(v[1]);
            //                it....it
            //  v[0].....v[1]
            int low_p, high_p, low, high;
            if (it == m.end()){
                low_p = INT_MAX;
                high_p = INT_MAX;
            }else{
                 low_p = it->first;
                 high_p = it->second;
            }
            it--;
            while(it!=m.begin()){
                int low = it->first;
                int high = it->second;
                if (high<=v[0]){
                    //    it....it
                    //             v[0].....v[1]
                    // no overlap paint
                    m[v[0]] = v[1];
                    break;
                }else if (high>v[0] && high<=v[1] && low<=v[0]){
                    //  it.....it        low_p.....high_p
                    //     v[0].....v[1]
                    //  it..........v[1] merge
                    if (v[1]<low_p){
                        m[low] = v[1];
                    }else{
                        //  it.....it low_p.....high_p
                        //     v[0].....v[1]
                        m.erase(low_p);
                        m[low] = high_p;
                    }
                    // add up overlap between it and v
                    i += high-v[0];
                    break;
                }else if (high>v[1] && low<=v[0]){
                    //    it.................it
                    //        v[0].....v[1]
                    // no change in map
                    i = v[1]-v[0];
                    break;
                }else if (it->first>v[0] && it->second<=v[1]){
                    //        it..it
                    //     v[0].....v[1]
                    i += high - low;
                    m.erase(low);
                    // reset it
                    it = m.lower_bound(v[1]);
                    it--;
                    // no need to update m as v will be captured later in first three cases
                }else if (low>v[0] && high>v[1]){
                    //              it.......it
                    //        v[0].....v[1]
                    i += v[1] - low;
                    // split it into two parts
                    m.erase(low);
                    m[v[1]] = high;
                    // reset it
                    it = m.lower_bound(v[1]);
                    it--;
                    // no need to update m as v will be captured later in first three cases
                }
            }
            
            // update 
            res.push_back(v[1]-v[0]-i);
        }
        return res;
    }
};
