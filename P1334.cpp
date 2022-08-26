/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional 
and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, 
If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Example 1:

Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
*/

#define DIST_MAX 10001 // weight>=1, distanceThreshold <=10^4

class Solution {
public:
    // Floyd Warshall Algorithm (Dynamic Programming)
    // Time Complexity: O(n^3)
    // Space Complexity: O(n^2)
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, DIST_MAX));
        int res(n);
        //Initialize diagonal of dp matrix, self loop is 0
        for(int v=0; v<n; ++v){
            dp[v][v] = 0;
        }
        // k=0, not use any mid point from i to j
        // connected with edge has edge[2] as value
        // not connected is disconnected, default DIST_MAX
        for (auto& edge:edges){
            dp[edge[0]][edge[1]] =edge[2];
            dp[edge[1]][edge[0]] = edge[2];
            
        }
        // from i to j, using first k nodes
        // case 1: not use node k-1, use 0....k-2 is dp[i][j][k-1]
        // case 2: use node k-1 dp[i][k-1][k-1]+dp[k-1][j][k-1]
        // using k nodes dp(i,j,k)= min(dp[i][j][k-1], dp[i][k-1][k-1]+dp[k-1][j][k-1] )
        // dp[i][j] = min(dp[i][j], dp[i][k-1]+dp[k-1][j])
        for(int k=1; k<=n;++k){
            for(int i =0; i<n;++i){
                for (int j=0;j<n;++j){
                    dp[i][j] = min (dp[i][j], dp[i][k-1]+dp[k-1][j]);
                }
            }
        }
        // count for each node reachable node numbers within threshold
        int resNode(0);
        for(int i = 0; i <n; ++i){
            int count(0);
            for(int j = 0;j <n; ++j){
                if(dp[i][j] <= distanceThreshold)
                    ++count;
            }
            if (count<res){
                res = count;
                resNode = i;
            } else if (count == res) {
                resNode = std::max(resNode, i);
            }
        }        
        
        return resNode;
    }
};
