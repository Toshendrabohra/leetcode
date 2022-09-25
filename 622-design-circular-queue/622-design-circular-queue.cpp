class MyCircularQueue {
public:
    int len, l, r;
    vector<int> queue;
    MyCircularQueue(int k) {
        len = k;
        l = 0;
        r = 0;
        queue.clear();
    }
    
    bool enQueue(int value) {
        if(r - l >= len)
            return false;
        r++;
        queue.push_back(value);
        
        return true;
    }
    
    bool deQueue() {
        if(l>=r)
            return false;
        l++;
        
        return true;
    }
    
    int Front() {
        if(l<r)
            return queue[l];
        else
            return -1;
    }
    
    int Rear() {
        if(r>l)
            return queue[r-1];
        else
            return -1;
    }
    
    bool isEmpty() {
        if(l==r)
            return true;
        return false;
    }
    
    bool isFull() {
        if(r-l >= len)
            return true;
        return false;
    }
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