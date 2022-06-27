/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements 
(it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

*/
class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool res = true;
        if (m.count(val)){
            res = false;
        }else{
            m[val] = data.size();
            data.push_back(val);
        }
        return res;
    }
    
    bool remove(int val) {
        bool res = true;
        if (m.count(val)){
            // swap to be removed value to the end
            int idx1 = m[val];
            int idx2 = data.size()-1;
            int tmp = data[idx1];
            data[idx1] = data[idx2];
            data[idx2] = tmp;
            // update map
            m[data[idx1]] = idx1;
            // remove val
            m.erase(val);
            data.pop_back();
        }else{
            res = false;
        }
        return res;
    }
    
    int getRandom() {
        return data[rand()%(data.size())];
    }
private:
    vector<int> data;
    // map data value with data index
    unordered_map<int,int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
