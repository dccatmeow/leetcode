class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        sz = k;
        l=0;
        len=0;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if (isFull()){
            return false;
        }
        // 1, 2, ?
        // ?, 2, 3
        int idx = (l+len)%sz;
        q[idx] = value;
        len++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()){
            return false;
        }
        // 0 , 1, 2, remove 0, l=1
        // back will circle back to 0, use q size and get residual
        l = (l+1)%sz;
        len--;
        return true;
    }
    
    int Front() {
        if (isEmpty()){
            return -1;
        }
        return q[l];
    }
    
    int Rear() {
        if (isEmpty()){
            return -1;
        }
        int idx = (l+len-1)%sz;
        return q[idx];
    }
    
    bool isEmpty() {
        return len==0;
    }
    
    bool isFull() {
        return len == sz; 
    }
    private:
    int sz;
    vector<int> q;
    int l,len;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
