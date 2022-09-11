/*
Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
 
Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
*/

class SnapshotArray {
public:
    using pii = std::pair<int,int>;
    SnapshotArray(int length) {
        // snapmem stores for each position
        // pii(snapshot#, value)
        snapmem = vector<vector<pii>>(length, vector<pii>());
    }
    
    void set(int index, int val) {
        // update mem
        mem[index] = val;
    }
    
    int snap() {
        // push mem into snapmem
        for (auto [index,val]:mem){
            snapmem[index].push_back(pii(snapCnt,val));
        }
        // update snap count
        snapCnt++;
        return snapCnt-1;
    }
    
    int get(int index, int snap_id) {
        int prev = 0;
        for (auto [i,j]:snapmem[index]){
            if (snap_id == i){
                return j;
            }else if (i>snap_id){
                // at snap_id, this index does not have an update
                // trace back to previous snapshot
                return prev;
            }
            prev = j;
        }
        return prev;
    }
private:
    int snapCnt = 0;
    // store each position's <snapshot#, value> change
    vector<vector<pii>> snapmem;
    // store index and value change between snapshot
    unordered_map<int,int> mem;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
