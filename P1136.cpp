/*1136. Parallel Courses
You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei.

In one semester, you can take any number of courses as long as you have taken all the prerequisites in the previous semester for the courses you are taking.

Return the minimum number of semesters needed to take all courses. If there is no way to take all the courses, return -1.

Example 1:
Input: n = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation: The figure above represents the given graph.
In the first semester, you can take courses 1 and 2.
In the second semester, you can take course 3.
Example 2:
Input: n = 3, relations = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: No course can be studied because they are prerequisites of each other.

*/
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        // problem can be formed to a tree and trying to find the longest path from leaf to root
        // if there is circle, then there is no way to finish the courses
        for (auto e:relations){
            m[e[0]].push_back(e[1]);
        }
        maxDepth = vector<int>(n+1, 0);
        int res(1);
        // loop through each class and find all the prerequisitions
        for (int i = 1; i<=n; ++i){
            int tmp = dfs(i, unordered_set<int>());
            if (tmp == -1){
                return -1;
            }
            res = max(res, tmp);
        }
        return res;
    }
    int dfs(int idx, unordered_set<int> path){
        if (maxDepth[idx]>0){
            return maxDepth[idx];
        }
        path.insert(idx);
        int tmp(1); // at least it needs 1 semester to finish itself
        for (auto e:m[idx]){
            if (path.find(e)!=path.end()){
                return -1;
            }
            int j = dfs(e, path);
            if (j == -1){
                // circular dependency
                return -1;
            }
            tmp = max(tmp, j+1);
        }
        maxDepth[idx] = tmp;
        return tmp;
    }
private:
    unordered_map<int,vector<int>> m;
    vector<int> maxDepth;
};
