class RandomizedCollection {
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        if (m.find(val)!=m.end()){
            data.push_back(val);
            m[val].push_back(data.size()-1);
            return false;
        }
        data.push_back(val);
        m[val].push_back(data.size()-1);
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val)==m.end()){
            return false;
        }
        // swap m[val].back() with last element in data
        int idxSwap = m[val].back();
        int lastValue = data.back();
        data[idxSwap] = lastValue;
        m[lastValue].back() = idxSwap;
        m[val].pop_back();
        data.pop_back();
        if (m[val].size()==0){
            m.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int num = rand()%data.size();
        return data[num];
    }
private:
    unordered_map<int,vector<int>> m; // value, index vector
    vector<int> data;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
