/*
You are given a stream of points on the X-Y plane. Design an algorithm that:

Adds new points from the stream into a data structure. Duplicate points are allowed and should be treated as different points.
Given a query point, counts the number of ways to choose three points from the data structure such that the three points 
and the query point form an axis-aligned square with positive area.
An axis-aligned square is a square whose edges are all the same length and are either parallel or perpendicular to the x-axis and y-axis.

Implement the DetectSquares class:

DetectSquares() Initializes the object with an empty data structure.
void add(int[] point) Adds a new point point = [x, y] to the data structure.
int count(int[] point) Counts the number of ways to form axis-aligned squares with point point = [x, y] as described above.
*/

class DetectSquares {
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int i = point[0]*1001+point[1];
        // error: if (!freq.count(i)){
        // use check with 0 because later when we calculate frequency 
        // it will freq[i]=0 could be added.
        if (freq[i] == 0) {
            // add new element to m
            m[point[0]].push_back(point[1]);
        }
        // add to freq
        freq[i]++;
    }
    
    int count(vector<int> point) {
        int res(0);
        if (m.count(point[0])){
            // iterate through all the y
            for (auto y:m[point[0]]){
                if (y == point[1]){
                    continue;
                }else{
                    // point[0], point[1]     x,point[1]
                    // point[0],y             x,y
                    // possible x is 
                    int len = abs(point[1]-y);
                    // case 1
                    int x = point[0]+len;
                    int tmp = freq[x*1001+y] * freq[x*1001+point[1]];
                    res+= tmp* freq[point[0]*1001+y];
                    // case 2
                    if (point[0]>=len){
                        x = point[0]-len;
                        tmp= freq[x*1001+y] * freq[x*1001+point[1]];
                        res+= tmp* freq[point[0]*1001+y];
                    }
                }
            }
        }
        return res;
    }
private:
    // m[x] = y1,y2,...
    unordered_map<int, vector<int>> m;
    // x*1001+y, frequency
    unordered_map<int, int> freq;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
