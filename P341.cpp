/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    using it = vector<NestedInteger>::const_iterator;
public:
    // use stack for a pair of iterators
    // these iterator contains begin and end
    NestedIterator(vector<NestedInteger> &nestedList) {
        p.push({nestedList.begin(), nestedList.end()});
        findInteg(); // go to first integer
    }
    // [[1 2] 3 [ 4 5]]
    // stack looks like
    // [pair12 3 pair45]
    // [pair1 2]
    void findInteg(){
        // if reach last node of current vector, pop p
        // keep popping element till there is element to be visit
        while (p.top().first == p.top().second){
            p.pop();
            // check emptyness before calling top of a stack
            if (p.empty()){
                return;
            }
            // move to the next element in vector
            ++p.top().first;
        }
        if (p.top().first->isInteger()){
            // find integer from begin iterator
            return;
        }else{
            // find a vector from begin interator
            // push vector's begin and end iterator into stack p
            // recursive call until fina a integer
            auto& tmp = p.top().first->getList();
            p.push({tmp.begin(), tmp.end()});
            findInteg();
        }
    }
    
    int next() {
        int val = p.top().first->getInteger();
        // move to next iterator and refresh p stack to find the next integer
        ++p.top().first;
        findInteg();
        return val;
    }
    
    bool hasNext() {
        return !p.empty();
    }
    
private:
    std::stack<std::pair<it,it>> p;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
