//223. Rectangle Area
// Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1)*(ay2-ay1);
        int area2 = (bx2-bx1)*(by2-by1);
        int deltax = max(0, min(ax2,bx2)-max(bx1,ax1));
        int deltay = max(0, min(ay2,by2)-max(ay1,by1));
        return area1+area2-deltax*deltay;
    }
};
