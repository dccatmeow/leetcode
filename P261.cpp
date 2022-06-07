class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Valid tree require the graph cannot have circle
        // it must include all the element
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        vector<bool> path(n, false);
        for(auto i:edges){
            graph[i[0]].emplace_back(i[1]);
            graph[i[1]].emplace_back(i[0]);
        }
        // no circle
        if (!traverse(graph, visited, path, 0, 0)){
            // circle detected, return false
            return false;
        }           
        // must visit all the element
        for (auto i:visited){
            if(i == false){
                return false;
            }
        }
        return true;
    }
    
    bool traverse(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>&path, int current, int prev){
        // set flag
        visited[current] = true;
        path[current] = true;
        for (auto i:graph[current]){
            // check if it is on path, circle detected
            if (path[i] && i!=prev){
                return false;
            }else if (!visited[i]){
                // visit non-visited node
                if (!traverse(graph, visited, path, i, current)){
                    return false;
                }
            }
        }
        // remove current node from path
        // moving back like back track
        path[current] = false;
        return true;
    }
    
};
