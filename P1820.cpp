/*1820 — Maximum Number of Accepted Invitations is a classic bipartite matching problem.
Core idea
You have:
grid[i][j] = 1 → boy i can invite girl j
Each boy can invite at most one girl.
Each girl can accept at most one invitation.
So this is maximum bipartite matching.
*/

class Solution {
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        int m = grid.size();       // number of boys
        int n = grid[0].size();    // number of girls
        
        vector<int> match(n, -1);
        int ans = 0;

        // Try to find a girl for boy u
        for (int u = 0; u < m; u++) {
            vector<bool> visited(n, false);

            if (dfs(u, grid, match, visited)) {
                ans++;
            }
        }

        return ans;
    }

private:
    bool dfs(int u,
             vector<vector<int>>& grid,
             vector<int>& match,
             vector<bool>& visited) {

        int n = grid[0].size();

        for (int v = 0; v < n; v++) {
            if (grid[u][v] == 0 || visited[v])
                continue;

            visited[v] = true;

            // Girl v is free, OR
            // the boy currently matched to v can find another girl
            if (match[v] == -1 || 
                dfs(match[v], grid, match, visited)) {

                match[v] = u;
                return true;
            }
        }

        return false;
    }
};
