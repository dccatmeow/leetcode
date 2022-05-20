/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
  */

class LRUCache {
public:
    using pii = std::pair<int,int>;
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        int val = -1;
        if (m.count(key)){
            val = m[key]->second;
            put(key, val);
        }
        return val;
    }
    
    void put(int key, int value) {
        if (m.count(key)){
            // remove key in list
            l.erase(m[key]);
        }
        if (l.size() == c){
            // exceeding the capacity pop front element first
            // the least used item
            m.erase(l.front().first);
            l.pop_front();
        }
        // inset key value pair at the end
        l.push_back(pii(key, value));
        m[key] = --l.end();
    }
private:
    int c;
    // hash table store key, iterator in list l 
    unordered_map<int, list<pii>::iterator> m;
    // pii is key, value pair
    list<pii> l;    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
