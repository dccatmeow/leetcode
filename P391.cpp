/*
Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

Return true if all the rectangles together form an exact cover of a rectangular region.

 

Example 1:


Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.
*/


class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        if (n== 1){
            return true;
        }
        // sort rectangles by first element
        auto comp = [](vector<int> const& v1, vector<int> const& v2){ //**** const&
            return v1[0]<v2[0];
        };
        sort(rectangles.begin(), rectangles.end(), comp);

        int minx(INT_MAX); // min of x
        int maxx(INT_MIN); // max of x
        int miny(INT_MAX); //min of y
        int maxy(INT_MIN); // max of y
        
        for(auto const& v:rectangles){ //*****const &
            minx = min(minx,v[0]);
            maxx = max(maxx,v[2]);
            maxy = max(maxy,v[3]); // max of y
            miny = min(miny,v[1]); //min of y
        }
        
        int data[maxy-miny+1];
        std::fill(data, data+maxy-miny+1, minx);
       
        for (auto const& v:rectangles){// *****const &
            // v [x,y,a,b]
            // x-on, a-off
            // y axis loop through (y, b] to avoid duplicate
            for (int y = v[1]+1-miny; y<=v[3]-miny; ++y) {
                if (data[y] == v[0]){
                    data[y] = v[2];
                }else{
                    return false;
                }
            }
            // check miny row
            if (v[1] == miny){
                // check y row, if current x is data[y]
                if (data[0]==v[0]){
                    data[0] = v[2];
                }else{
                    return false;
                }
            }
        }
        
        for (int i=0; i<maxy-miny+1; ++i) {
            if (data[i] != maxx) {
                return false;
            }
        }
        
        return true;
    }
};
