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

        // match[girl] = boy currently matched to this girl
        vector<int> match(n, -1);

        int ans = 0;

        for (int boy = 0; boy < m; boy++) {
            // Tracks girls already explored in this augmenting path
            vector<bool> pathVisited(n, false);

            if (dfs(boy, grid, match, pathVisited)) {
                ans++;
            }
        }

        return ans;
    }

private:
    bool dfs(int boy,
             vector<vector<int>>& grid,
             vector<int>& match,
             vector<bool>& pathVisited) {

        int n = grid[0].size();

        for (int girl = 0; girl < n; girl++) {

            // Boy cannot invite this girl,
            // or we've already tried this girl in this path.
            if (grid[boy][girl] == 0 || pathVisited[girl]) {
                continue;
            }

            pathVisited[girl] = true;

            // Case 1: Girl is free
            if (match[girl] == -1) {
                match[girl] = boy;
                return true;
            }

            // Case 2: Girl is already matched.
            // Try to move the current boy to another girl.
            int currentBoy = match[girl];

            if (dfs(currentBoy, grid, match, pathVisited)) {
                match[girl] = boy;
                return true;
            }
        }

        return false;
    }
};
