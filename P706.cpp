class MyHashMap {
public:
    // use vector for key matching and use linked list to resolve collision of keys 
    /** Initialize your data structure here. */
    MyHashMap() {
        data.resize(1009);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashVal = key%1009;
        auto& lst = data[hashVal];
        for(auto& it:lst){
            if(it.first == key){
                it.second = value;
                return;
            }
        }
        lst.push_back(std::pair<int,int>(key,value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashVal = key%1009;
        auto& lst = data[hashVal];
        for(auto& it:lst){
            if(it.first == key){
                return it.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashVal = key%1009;
        auto& lst = data[hashVal];
        for(auto it=lst.begin(); it!=lst.end(); ++it){
            if(it->first == key){
                lst.erase(it);
                return;
            }
        }
    }
    private:
    std::vector<std::list<std::pair<int,int>>> data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
