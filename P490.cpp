/*
490. The Maze

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).


*/

class Solution {
public:
using pii=std::pair<int,int>;
vector<pii> direction{{1,0},{0,1},{-1,0},{0,-1}};
int m, n;
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m=maze.size();
        n=maze[0].size();
        queue<pii> q;
        q.push(pii(start[0],start[1]));
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        visited[start[0]][start[1]] = true;
        while(!q.empty()){
            int sz=q.size();
            for (int i=0; i<sz;++i){
                auto [x,y] = q.front();
                q.pop();
                if (x==destination[0]&& y==destination[1]){
                    return true;
                }
                for (auto [dx,dy]:direction){
                    int tmpx = dx+x;
                    int tmpy = dy+y;
                    // go straight till hit the wall
                    while(tmpx>=0 && tmpy>=0 && tmpx<m && tmpy<n 
                    && maze[tmpx][tmpy]==0){
                        tmpx+=dx;
                        tmpy+=dy;
                    }
                    // retreat one step to open space
                    tmpx-=dx;
                    tmpy-=dy;
                    if (!visited[tmpx][tmpy]){
                        q.push(pii(tmpx,tmpy));
                        visited[tmpx][tmpy]=true;
                    }
                }
            }
        }
        return false;
    }
};
