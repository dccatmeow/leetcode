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
private:
    struct Node {
        int value;
        int freq;
        list<int>::iterator it;
    };

    int capacity;
    int minFreq;

    // key -> {value, freq, iterator in freq list}
    unordered_map<int, Node> keyMap;

    // freq -> list of keys (LRU order within same frequency)
    unordered_map<int, list<int>> freqMap;

    void touch(int key) {
        auto &node = keyMap[key];
        int oldFreq = node.freq;
        // Remove from old frequency list
        freqMap[oldFreq].erase(node.it);
        // Remove empty frequency list
        if (freqMap[oldFreq].empty()) {
            freqMap.erase(oldFreq);
            if (minFreq == oldFreq)
                minFreq++;
        }
        // Increase frequency
        node.freq++;
        // Add to new frequency list
        freqMap[node.freq].push_back(key);
        node.it = prev(freqMap[node.freq].end());
    }

public:
    LFUCache(int capacity)
        : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) return -1;
        touch(key);
        return keyMap[key].value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        // Key already exists
        if (keyMap.find(key) != keyMap.end()) {
            keyMap[key].value = value;
            touch(key);
            return;
        }
        // Cache full: remove LFU
        if (keyMap.size() == capacity) {
            int oldKey = freqMap[minFreq].front();
            freqMap[minFreq].pop_front();
            if (freqMap[minFreq].empty())
                freqMap.erase(minFreq);
            keyMap.erase(oldKey);
        }

        // Insert new key with frequency 1
        minFreq = 1;
        freqMap[1].push_back(key);
        Node node;
        node.value = value;
        node.freq = 1;
        node.it = --(freqMap[1].end());
        keyMap[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
