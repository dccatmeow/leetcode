/*
Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. 
The sign of grid[i][j] can be:

1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) 
and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

Example 1:

Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
*/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // dijkistra
        // from [0,0] to [m-1,n-1]
        int m=grid.size();
        int n=grid[0].size();
        // priority queue [i,j,k], grid[i][j]
        // k is the sign modification times
        auto comp = [](vector<int>& v1, vector<int>& v2){
            return v1[2] > v2[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> q(comp);
        q.push(vector<int>{0,0,0});
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        // maximum move needed to get to [m-1][n-1]
        int res = m+n-2;
        while(!q.empty()){
            auto v = q.top();
            if (v[0] == m-1 && v[1] == n-1){
                return v[2];
            }
            q.pop();
            if (visited[v[0]][v[1]]){
                continue;
            }else{
                visited[v[0]][v[1]] = true;
            }
            // up
            auto tmp = v;
            if (v[0]>0){
                tmp[0]-=1;
                if (grid[v[0]][v[1]] != 4){
                    tmp[2]++;
                }
                if (tmp[2] < res){
                    q.push(tmp);
                }
            }
            //down
            tmp = v;
            if (v[0]<m-1){
                tmp[0]+=1;
                if (grid[v[0]][v[1]] != 3){
                    tmp[2]++;
                }
                if (tmp[2] < res){
                    q.push(tmp);
                }
            }
            // left
            tmp = v;
            if (v[1]>0){
                tmp[1]-=1;
                if (grid[v[0]][v[1]] != 2){
                    tmp[2]++;
                }
                if (tmp[2] < res){
                    q.push(tmp);
                }
            }
            // right
            tmp = v;
            if (v[1]<n-1){
                tmp[1]+=1;
                if (grid[v[0]][v[1]] != 1){
                    tmp[2]++;
                }
                if (tmp[2] < res){
                    q.push(tmp);
                }
            }
        }
        // worst case
        return m+n-2;
    }
};
