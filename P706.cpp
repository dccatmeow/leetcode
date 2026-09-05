class MyHashMap {
private:
    vector<vector<pair<int, int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        buckets.resize(1000);
    }

    void put(int key, int value) {
        int index = hash(key);

        for (auto& [k, v] : buckets[index]) {
            if (k == key) {
                v = value;   // update existing key
                return;
            }
        }

        buckets[index].push_back({key, value});
    }

    int get(int key) {
        int index = hash(key);

        for (auto& [k, v] : buckets[index]) {
            if (k == key) {
                return v;
            }
        }

        return -1;
    }

    void remove(int key) {
        int index = hash(key);

        for (auto it = buckets[index].begin();
             it != buckets[index].end();
             ++it) {

            if (it->first == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
