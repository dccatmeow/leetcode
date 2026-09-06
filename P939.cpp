/*
939. Minimum Area Rectangle
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

Return the minimum area of a rectangle formed from these points, with sides parallel 
to the X and Y axes. If there is not any such rectangle, return 0.
*/

class Solution {
public:
    string encode(int x, int y) {
        return to_string(x) + "#" + to_string(y);
    }

    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<string> pointSet;

        for (auto& p : points) {
            pointSet.insert(encode(p[0], p[1]));
        }

        int ans = INT_MAX;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // They must be diagonal corners:
                // different x AND different y
                if (x1 == x2 || y1 == y2) {
                    continue;
                }

                // Check the other two corners
                if (pointSet.count(encode(x1, y2)) &&
                    pointSet.count(encode(x2, y1))) {

                    int width = abs(x1 - x2);
                    int height = abs(y1 - y2);

                    ans = min(ans, width * height);
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

// Time complexity O(n2)
// space complexity O(n)
