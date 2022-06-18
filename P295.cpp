/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
*/

class MedianFinder {
public:
    MedianFinder() {
        // use two priority queue
        // l s
        // l.size and s.size is equal or difference with 1
        // e1....e2, e3....e4
        // e2 is the top of max heap l
        // e3 is the top of min heap s
        // the median number is either e2 or e3 or 0.5(e2+e3)
    }
    
    void addNum(int num) {
        // time complexity O(logN)
        if (scount<lcount){
            // s has fewer element
            // s should add one element at this round
            // first push element to l
            // largest element is now in top of l
            // move this element to s
            l.push(num);
            s.push(l.top());
            l.pop();
            scount++;
        }else{
            s.push(num);
            l.push(s.top());
            s.pop();
            lcount++;
        }
    }
    
    double findMedian() {
        // time complexity O(1)
        if (lcount>scount){
            return l.top();
        }else if (scount>lcount){
            return s.top();
        }else{
            return 0.5*(l.top()+s.top());
        }
    }
    
private:
    priority_queue<int> l; // max heap
    priority_queue<int, vector<int>, greater<int>> s; // min heap
    int lcount{0}, scount{0};
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
