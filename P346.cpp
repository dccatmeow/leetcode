/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.
*/

class MovingAverage {
public:
    MovingAverage(int size) {
        sz=size;
    }
    
    double next(int val) {
        int n = q.size();
        if(n<sz){
            mem = (mem+val);
        }else{
            mem = mem-q.front()+val;
            q.pop();
        }
        q.push(val);
        return mem/q.size();
    }
private:
    int sz{1};
    queue<int> q;
    double mem;
};
