/*
Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

Example 1:

Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]
*/

class FreqStack {
public:
    FreqStack() {
        // initialize v
        v.push_back(stack<int>());
    }
    
    void push(int val) {
        ++m[val];
        int freq = m[val];
        if (v.size()==freq){
            v.push_back(stack<int>());
        }
        v[freq].push(val);
        maxFreq = max(maxFreq, freq);
    }
    
    int pop() {
        int val = v[maxFreq].top();
        m[val]--;
        v[maxFreq].pop();
        // refresh maxFreq
        while(maxFreq>0 && v[maxFreq].empty()){
            maxFreq--;
        }
        return val;
    }
private:
    // frequency, value
    // v[1] is stack of values that occurred once
    vector<stack<int>> v;
    // value, frequency
    unordered_map<int, int> m;
    // store max frequence for pop
    int maxFreq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
