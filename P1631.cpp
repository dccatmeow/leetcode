/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), 
and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, 
and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    // BFS, Dijkstra
        int m=heights.size();
        int n=heights[0].size();
        // visited
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // priority queue pii(max diff between neighbors from start to current node, x, y)
        auto comp = [](const auto& v1, const auto& v2){
            return v1[0]>v2[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp) > q(comp);
        q.push(vector<int>{0,0,0});
        int res(0);
        while(!q.empty()){
            auto v = q.top();
            q.pop();
            if (!visited[v[1]][v[2]]){
                // node has not been visited
                visited[v[1]][v[2]] = true;
                if(v[1]==m-1 && v[2] == n-1){
                    // reach bottom right corner
                    return v[0];
                }
                auto next = std::vector<std::pair<int, int>>{
                    {v[1]-1,v[2]},{v[1]+1,v[2]},{v[1],v[2]-1},{v[1],v[2]+1}};
                for (auto const& [i, j] : next) {
                    if (i<0||j<0||i>m-1||j>n-1){
                        continue;
                    }
                    int dif = max(v[0], abs(heights[v[1]][v[2]]-heights[i][j]));
                    q.push(vector<int>{dif , i,j});
                    
                }
            }
        }
        return res;
    }
};
// time complexity Olog(number of all the element)*n
// space complexity O(n)
