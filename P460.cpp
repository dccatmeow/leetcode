/*
460. LFU Cache

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, 
it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie 
(i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. 
The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). 
The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/
class LFUCache {
public:
    LFUCache(int capacity) {
        cap=capacity;
        c=0;
    }
    
    int get(int key) {
        if (data.find(key)==data.end()){
            return -1;
        }else{
            put(key, data[key]);
            return data[key];
        }
    }
    
    void put(int key, int value) {
        if (data.find(key)==data.end()){
            // add new entry
            if (c == cap){
                int k = freq.begin()->second.front();
                freq.begin()->second.pop_front();
                data.erase(k);
                m.erase(k);
                c--;
            }
            c++;
            freq[1].push_back(key);
            auto iter = --freq[1].end();
            m[key] = std::pair<int, list<int>::iterator> (1, iter);
        }else{
            // erase old entry
            auto [f,iter] = m[key];
            freq[f].erase(iter);
            if (freq[f].empty()){
                // remove empty key
                freq.erase(f);
            }
            freq[f+1].push_back(key);
            m[key] = std::pair<int, list<int>::iterator> (f+1, --freq[f+1].end());
        }
        data[key]=value;
    }
private:
    map<int,list<int>> freq; // frequency, list of keys
    unordered_map<int,int> data; // key value
    unordered_map<int, std::pair<int, list<int>::iterator> > m; // key, frequency, iterator
    int c;
    int cap;

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
