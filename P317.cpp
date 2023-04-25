/*
You are given an m x n grid grid of values 0, 1, or 2, where:

each 0 marks an empty land that you can pass by freely,
each 1 marks a building that you cannot pass through, and
each 2 marks an obstacle that you cannot pass through.
You want to build a house on an empty land that reaches all buildings in the shortest total travel distance. You can only move up, down, left, and right.

Return the shortest travel distance for such a house. If it is not possible to build such a house according to the above rules, return -1.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.
*/

static const pair<int, int> dir[] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

class Solution {
public:
    vector<vector<int>> rank; // at each location that can be house, add up distance to each building
    vector<vector<int>> cnt;
    vector<pair<int, int>> buildings; // location of all the buildings
    vector<vector<int>> * _grid;
    int m, n;
    
    void build(vector<vector<int>>& grid)
    {
        // find all the building
        m = grid.size();
        n = grid[0].size();
        _grid = &grid;

        rank.resize(m, vector<int>(n, 0));
        cnt.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    buildings.push_back({i, j});
                }
            }
        }
    }

    void bfs(int x, int y)
    {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<vector<int>> & grid = *_grid;

        q.push({x, y});
        int dist = 1;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz > 0)
            {
                sz--;
                auto [x, y] = q.front();
                q.pop();

                for (const auto [dx, dy] : dir)
                {
                    int nx = x + dx, ny = y + dy;
                    if (0 <= nx && nx < m && 0 <= ny && ny < n &&
                        grid[nx][ny] == 0 && visited[nx][ny] == false)
                    {
                        rank[nx][ny] += dist;
                        visited[nx][ny] = true;
                        cnt[nx][ny] ++;
                        q.push({nx, ny});
                    }
                }
            }
            dist ++;
        }
    }

    int best()
    {
        // find the best location with shortest distance to all the buildings
        vector<vector<int>> & grid = *_grid;
        int n_buildings = buildings.size();

        int minDist = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0 && cnt[i][j] == n_buildings)
                {
                    minDist = std::min(minDist, rank[i][j]);
                }
            }
        }
        return minDist;
    }

    int shortestDistance(vector<vector<int>>& grid) {
        build(grid);
        for (auto [x, y] : buildings)
        {
            bfs(x, y);
        }
        int ans = best();
        return ans == INT_MAX ? -1 : ans;
    }
};
