2332. The Latest Time to Catch a Bus

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int p(0);// index passengers
        int c; // trace capacity for each bus
        for (auto t:buses){
            int i=0;
            while(i<capacity && p<passengers.size() && t>=passengers[p]){
                // passenger can get on buses
                i++;
                p++;
            }
            c = i;
        }
        // check last bus
        if (c==capacity){
            // buses is full
            if (p==0){
                return passengers[0]-1;
            }
            p--;
            // should return passenger[p]-1, while there may be passenger at this time.
            while(p>0 && passengers[p-1] == passengers[p]-1){
                p--;
            }
            return passengers[p]-1;
        }else{
            // should return buses[buses.size()-1], while there may be passenger at this time.
            int i = buses.size()-1;
            if (p==0){
                if (passengers[0] == buses[0]){
                    return passengers[0]-1;
                } else{
                    return buses[i];
                }
            }
            p--;
            if (passengers[p] == buses[i]){
                // find the passenger not in sequence
                while(p>0 && passengers[p-1] == passengers[p]-1){
                    p--;
                }
                return passengers[p]-1;
            }else{
                // last person at last minute
                return buses[i];
            }
        }
    }
};
Console
