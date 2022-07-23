/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/

class MyHashSet {
public:
    // Hash with chaining
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(1009);
    }
    
    void add(int key) {
        int k = key%1009;
        auto& lst = data[k];
        auto it = find(lst.begin(), lst.end(), key);
        if (it==lst.end()){
            lst.push_back(key);
        }
    }
    
    void remove(int key) {
        int k = key%1009;
        auto& lst = data[k];
        // find element to remove from linked list
        auto it = find(lst.begin(), lst.end(), key);
        if (it!=lst.end()){
            lst.erase(it);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int k = key%1009;
        auto& lst = data[k];
        auto it = find(lst.begin(), lst.end(), key);
        if (it!=lst.end()){
            return true;
        }
        return false;
    }
    
    private:
    std::vector<std::list<int>> data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
