/*
There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height
(i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, 
then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, 
in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.
*/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // the least bricks is where most edge on a vertical line
        int res = 0;
        unordered_map<int, int> myMap;// key is edge position, value is count
        // get edge of bricks for each row
        for (auto row:wall){
            int sum = 0;
            for (auto b:row){ // exclude right edge of wall
                sum += b;
                myMap[sum]++;
            }
            // remove the last position, right edge
            myMap[sum] = 0;
        }       
        // find max count in myMap
        for (auto it = myMap.begin(); it != myMap.end(); ++it){
            if (it->second > res){
                res = it->second;
            }
        }
        res = wall.size() - res;
        return res;
    }
};
