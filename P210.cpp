/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // use graph to traverse all the possible path
        int n = prerequisites.size();
        visited = vector<bool>(numCourses,false);
        // create graph, prerequisite is the value
        for (auto v:prerequisites){
            graph[v[0]].push_back(v[1]);
        }

        // traverse from all the starting case for prerequisites
        for(int i=0; i<numCourses; ++i){
            if (!visited[i]){
                // use a path to track if there is a circle in path
                vector<bool> path(numCourses, false);
                if (traverse(prerequisites, i, path)){
                    // find a circle
                    return {};
                };
            }
        }
        return res;
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
        res.push_back(i);
        return false;
    }
    
private:
    unordered_map<int, vector<int>> graph;
    vector<bool> visited;
    vector<int> res;
};

// time complexity O(numCourses)
// space complexity O(numCourses)
