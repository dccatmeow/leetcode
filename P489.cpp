/**
You are controlling a robot that is located somewhere in a room. The room is modeled as an m x n binary grid where 0 represents a wall 
and 1 represents an empty slot.

The robot starts at an unknown location in the room that is guaranteed to be empty, and you do not have access to the grid, 
but you can move the robot using the given API Robot.

You are tasked to use the robot to clean the entire room (i.e., clean every empty cell in the room). 
The robot with the four given APIs can move forward, turn left, or turn right. Each turn is 90 degrees.

When the robot tries to move into a wall cell, its bumper sensor detects the obstacle, and it stays on the current cell.

Design an algorithm to clean the entire room using the following APIs:

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}

 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    // assume robort facing up at beginning
    // 4 directions
    // up, right, down, left
    // 0   1     2      3
    vector<pair<int,int>> direction{{0,1}, {1,0}, {0,-1}, {-1,0}};
    // down, left, up, right
    vector<int> reverseD{2,3,0,1};
    void cleanRoom(Robot& robot) {
        // original position is [0,0]
        // direction [0,1,2,3]
        tr(robot, 0, 0, 0);
    }
    void tr(Robot& robot, int i, int j, int d){
        // visit robot at position [i, j], facing d
        robot.clean();
        visited.insert(to_string(i)+'*'+to_string(j));
        
        for (int k=0; k<4; ++k){
            // turn to k
            turnDirection(robot, d,k);
            // move
            bool tmp = robot.move();
            if (tmp){
                int x = i+direction[k].first;
                int y = j+direction[k].second;
                // robot moved
                if (!visited.count(to_string(x)+'*'+to_string(y))){
                    tr(robot, x, y, k);
                }
            }   
            // reverse direction and move
            if (tmp){
                turnDirection(robot, k, reverseD[k]);
                // reverse by move 1
                robot.move();
                turnDirection(robot, reverseD[k], d);
            }else{
                // restore direction
                turnDirection(robot,k,d);
            }
        }
    }
    
    void turnDirection(Robot& robot, int p, int p_new){
        // get to correct direction
        if (p<p_new){
            // turn right
            for (int i=p; i<p_new; ++i){
                robot.turnRight();
            }
        }else{
            // turn left
            for (int i=p; i>p_new; --i){
                robot.turnLeft();
            }
        }
    }
private:
    unordered_set<string> visited;
};
