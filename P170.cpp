/*
Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.

Implement the TwoSum class:

TwoSum() Initializes the TwoSum object, with an empty array initially.
void add(int number) Adds number to the data structure.
boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value, otherwise, it returns false.
 

Example 1:

Input
["TwoSum", "add", "add", "add", "find", "find"]
[[], [1], [3], [5], [4], [7]]
Output
[null, null, null, null, true, false]

Explanation
TwoSum twoSum = new TwoSum();
twoSum.add(1);   // [] --> [1]
twoSum.add(3);   // [1] --> [1,3]
twoSum.add(5);   // [1,3] --> [1,3,5]
twoSum.find(4);  // 1 + 3 = 4, return true
twoSum.find(7);  // No two integers sum up to 7, return false
*/


class TwoSum {
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        m[number]++;
    }
    
    bool find(int value) {
        for (auto it = m.begin(); it!=m.end(); it++){
            long long tmp = static_cast<long long>(value)-it->first;
            if (tmp>INT_MAX || tmp<INT_MIN){
                break;
            }
            // check two numbers identical case
            if (value-it->first == it->first){
                if(it->second>=2){
                    return true;
                }
            }else{
                if (m.count(value-it->first)){
                return true;
                }
            }
            
        }
        return false;
    }
private:
    unordered_map<int,int> m;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
