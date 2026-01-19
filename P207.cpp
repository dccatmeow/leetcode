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
        // this problem tries to find the circular dependency
        vector<vector<int>> v(numCourses, vector<int>());
        res = 0;
        visited = vector<int>(numCourses, 0);
        for (auto e:prerequisites){
            int n0 = e[0];
            int n1 = e[1];
            v[n1].push_back(n0);
        }
        for (int i=0; i<numCourses;++i){
            if(visited[i]==0 && !dfs(v,i)){
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& v, int i){
        // flag
        visited[i] = 1;
        for (auto e:v[i]){
            if (visited[e]==1) return false;
            else if (visited[e]==2) continue;
            if (!dfs(v,e)) return false;
        }
        visited[i]=2;
        return true;
    }
private:
    vector<int> visited;
    int res;
};
// time complexity O(numCourses+prerequisites)
// space complexity O(numCourses+prerequisites)
