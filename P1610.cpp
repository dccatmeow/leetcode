/*
You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] 
both denote integral coordinates on the X-Y plane.
Initially, you are facing directly east from your position. 
You cannot move from your position, but you can rotate. In other words, 
posx and posy cannot be changed. Your field of view in degrees is represented by angle, 
determining how wide you can see from any given view direction. 
Let d be the amount in degrees that you rotate counterclockwise. 
Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].

You can see some set of points if, for each point, the angle formed by the point,
your position, and the immediate east direction from your position is in your field of view.

There can be multiple points at one coordinate. There may be points at your location, 
and you can always see these points regardless of your rotation. Points do not obstruct your vision to other points.

Return the maximum number of points you can see.
*/

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        // get relative angle from location to point
        vector<double> p;
        double pi = acos(-1.0);
        int origin(0);
        for(auto v: points){
            // v[0] v[1]
            // location[0] location[1]
            if (v[0] == location[0]&& v[1] == location[1]){
                // overlapping with origin, origin can fall in any angle
                origin++;
                continue;
            }
            double an = atan2(v[1]-location[1], v[0]-location[0]); //rad
            an = an*180/pi;
            p.push_back(an);
            // add second round for all the point
            p.push_back(an+360);
        }
        std::sort(p.begin(), p.end());
        int res(0);
        for (int i=0; i<p.size();++i){
            // find the first element that is out of bound
            int cnt = upper_bound(p.begin(), p.end(), p[i]+angle) - p.begin();
            res = max(res, cnt-i);
        }
        return res+origin;
    }
};
