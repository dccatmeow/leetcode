/*155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push_back(val);
        // push to minS if it is empty or
        if (minS.size()==0 || val <= minS.back()){
            minS.push_back(val);
        }
    }
    
    void pop() {
        if (!s.empty() && s.back() == minS.back()){
            minS.pop_back();
        }
        s.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return minS.back();
    }
private:
    vector<int> s;
    vector<int> minS;
    

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
