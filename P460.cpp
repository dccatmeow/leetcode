/*
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
using pii = pair<int,int>; 
using piter = pair< list<int>::iterator, list<pii>::iterator >;
public:
    LFUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if (c ==0){
            return -1;
        }
        if (keym.count(key)){
            int value = keym[key].second->second;
            put(key, value);
            return value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (c==0){
            return;
        }
        if (keym.count(key)){
            // update value
            // get existing iterators
            auto [fiter, iter] = keym[key];
            // add key value
            int newfreq = *fiter+1;
            auto newfreqiter = fiter;
            if (!freqm.count(newfreq)){
                // add new frequence
                newfreqiter = freq.insert(++newfreqiter, newfreq);
            }else{
                // move iterator one more
                newfreqiter++;
            }
            freqm[newfreq].push_back(pii(key,value));
            keym[key] = piter(newfreqiter, --(freqm[newfreq].end()) );
            // remove old key,value pair in frequence map to key value pair
            freqm[*fiter].erase(iter);
            // if no element in this old frequency, remove it from map and list of frequency
            if (freqm[*fiter].empty()){
                freqm.erase(*fiter);
                freq.erase(fiter);
            }
            return;
        }
        
        if (count == c){
            // remove lease frequently used
            int oldkey = freqm[freq.front()].front().first;
            freqm[freq.front()].pop_front();
            // check if first key of freq is empty
            if (freqm[freq.front()].empty()){
                freqm.erase(freq.front());
                freq.pop_front();
            }
            keym.erase(oldkey);
            count--;
        }
        // add new key value
        if (!freqm.count(1)){
            // freqm[1] does not exist, create a new element in freq
            freq.insert(freq.begin(),1);
        }
        freqm[1].push_back(pii(key, value));
        keym[key] = piter(freq.begin(), --(freqm[1].end()) );
        count++;
    }
private:
    // list of all the frequences e.g. 1,2,4,...
    list<int> freq;
    // hash table for frequence to list of key,value pair
    unordered_map<int, list<pii>> freqm;
    // hash table for key to frequence iterator and key,value pair iterator
    unordered_map<int, piter> keym;
    int c;
    int count = 0;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
