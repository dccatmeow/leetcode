class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        using pii = std::pair<int,int>;
        vector<vector<int>> g(n);
        for (int i=0; i<n;++i){
            if (manager[i] != -1){
                // not head
                g[manager[i]].push_back(i);
            }
        }
        queue<pii> q;
        int res(0);
        q.push({0, headID});
        while(!q.empty()){
            int l = q.size();
            for(int i=0; i<l; ++i){
                auto [time, node] = q.front();
                q.pop();
                for (auto e:g[node]){
                    q.push({time+informTime[node], e});
                }
                res = max(time, res);
            }
        }
        return res;
    }
};
