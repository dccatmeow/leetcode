In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, 
then one square in an orthogonal direction.

Return the minimum number of steps needed to move the knight to the square [x, y]. It is guaranteed the answer exists.

 class Solution {
public:
    using pii = std::pair<int,int>;
    int minKnightMoves(int x, int y) {
        if (x==0 && y==0){
            return 0;
        }
        // the steps to go to x,y is the same steps to go to abs(s), abs(y)
        // due to the symmetric property in this question
        int step(0);
        int targetx = abs(x);
        int targety = abs(y);
        // directions
        vector<pii> direct{{1,2}, {1,-2}, {2,1}, {2,-1}, {-1,2},{-1,-2},{-2,1},{-2,-1}};
        // BFS
        queue<pii> q;
        unordered_map<int,unordered_map<int,int>> visited;
        // initial condition
        q.push({0,0});
        while(!q.empty()){
            int len = q.size();
            for (int i=0; i<len; ++i){
                auto [tx, ty] = q.front();
                q.pop();
                for (auto [dx,dy]:direct){
                    // calculate new locations
                    dx = abs(dx+tx);
                    dy = abs(dy+ty);
                    if (visited.count(dx) && visited[dx].count(dy)){
                        // node visited
                        continue;
                    }else if (dx == targetx && dy == targety){
                        return step+1;
                    }else{
                        q.push({dx,dy});
                        visited[dx][dy] = step+1;
                    }
                }
            }
            step++;
        }
        return min(step, INT_MAX);
    }
};
