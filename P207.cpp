/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // use graph to traverse all the possible path
        int n = prerequisites.size();
        visited = vector<bool>(numCourses,false);
        // create graph
        for (auto v:prerequisites){
            graph[v[1]].push_back(v[0]);
        }

        // traverse from all the starting case for prerequisites
        for(auto v:prerequisites){
            if (!visited[v[1]]){
                // use a path to track if there is a circle in path
                vector<bool> path(numCourses, false);
                if (traverse(prerequisites, v[1], path)){
                    // find a circle
                    return false;
                };
            }
        }
        return true;
    }
    
    bool traverse(vector<vector<int>>& prerequisites, int i, vector<bool>& path){
        // if there is a circle, return true, else false
        visited[i] = true;
        path[i] = true;
        if (graph.count(i)){
            // in the graph, loop through all the next level nodes
            for (auto j:graph[i]){
                if (path[j]){
                    // find a circle on path
                    return true;
                }
                if (!visited[j]){
                    // only excercise non visited cases
                    if(traverse(prerequisites, j, path)){
                        return true;
                    };
                }
            }
        }
        // now remove i from path as it finished search for current i
        path[i] = false;
        return false;
    }
    
private:
    unordered_map<int, vector<int>> graph;
    vector<bool> visited;
};

// time complexity O(numCourses)
// space complexity O(numCourses)
