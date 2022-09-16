/*
A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented 
as half-open intervals and query about them.

A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

Implement the RangeModule class:

RangeModule() Initializes the object of the data structure.
void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. 
Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) 
that are not already tracked.
boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently being tracked,
and false otherwise.
void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open interval [left, right).

Example 1:

Input
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
Output
[null, null, null, true, false, true]
*/

class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        if (m.empty()){
            m[left]=right;
        }
        auto it = m.upper_bound(right);
        if (it == m.begin()){
            // no overlap
            // left right keyL keyR
            m[left] = right;
            return;
        }
        // shift to left iterator
        it--;
        int keyL = it->first;
        int keyR = it->second;
        // no overlapping cases
        // keyL keyR left right
        if (keyR<left){
            m[left] = right;
            return;
        }
        // overlapping cases
        if (keyL<=left){
            // no new entry
            m[keyL] = max(right, keyR);
        }else{
            // left keyL ..
            m.erase(keyL);
            addRange(left, max(keyR, right));
        }
    }
    
    bool queryRange(int left, int right) {
        if (m.empty()){
            return false;
        }
        // there need to be a range contain left and right
        // to be able to return true
        auto it = m.upper_bound(left);
        if (it == m.begin()){
            // no match contains left and right
            return false;
        }
        // reduce iterator to find the correct range
        it--;
        int keyL = it->first;
        int keyR = it->second;
        //  keyL <= left right keyR
        if (keyL <=left && right<=keyR){
            return true;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        if (m.empty()){
            return;
        }
        auto it = m.upper_bound(right);
        if (it == m.begin()){
            return;
        }
        it--;
        int keyL = it->first;
        int keyR = it->second;
        // no overlapping case
        if (keyR<=left){
            return;
        }
        // overlapping cases
        if (left<=keyL){
            // left keyL
            m.erase(keyL);
            removeRange(left, keyL);
        }else if (keyL<left){
            m[keyL] = left;
        }
        if (right<keyR){
            // right   keyR
            m[right] = keyR;
        }        
    }
private:
    map<int, int> m;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
