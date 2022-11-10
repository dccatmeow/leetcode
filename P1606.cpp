/*
You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. 
Each server has infinite computational capacity but cannot handle more than one request at a time. 
The requests are assigned to servers according to a specific algorithm:

The ith (0-indexed) request arrives.
If all servers are busy, the request is dropped (not handled at all).
If the (i % k)th server is available, assign the request to that server.
Otherwise, assign the request to the next available server (wrapping around the list of servers and 
starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to 
the (i+1)th server, then the (i+2)th server, and so on.
You are given a strictly increasing array arrival of positive integers, where arrival[i] represents 
the arrival time of the ith request, and another array load, where load[i] represents the load of 
the ith request (the time it takes to complete). Your goal is to find the busiest server(s).
A server is considered busiest if it handled the most number of requests successfully among all the servers.

Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.

Example 1:


Input: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
Output: [1] 
*/

class Solution {
public:
using pii = std::pair<int,int>;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // busiest server handles max number of requests
        // free server set
        set<int> fs;
        // add free servers using circular array
        // i and i+k point to the same server
        for (int i=0; i<=2*(k-1); ++i){
            fs.insert(i);
        }
        int n=arrival.size();
        vector<int> cnt(k,0);
        // end time, server#
        // store currently running server
        priority_queue<pii, vector<pii>, greater<>> pq;
        // loop through all the element in arrival and assign it to server
        for (int i=0; i<n; ++i){
            // return free server
            while(!pq.empty() && arrival[i]>=pq.top().first){
                // free pq.top
                fs.insert(pq.top().second);
                fs.insert(pq.top().second+k);
                pq.pop();
            }   
            // check if free server available
            if (!fs.empty()){
                // circular array, lower bound returns
                // server s or s+k, with mod k returns the correct server
                int server = (*fs.lower_bound(i%k))%k;
                // remove server from free server set
                fs.erase(server);
                fs.erase(server+k);
                pq.push(pii(arrival[i]+load[i],server));
                cnt[server]++;
            }
        }
        vector<int> res;
        int tmp = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        for (int i=0; i<cnt.size(); i++){
            if (cnt[i]==cnt[tmp]){
                res.push_back(i);
            }
        }
        return res;
    }
};
