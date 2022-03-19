class FreqStack {
public:
    int max_freq=0;
    unordered_map<int,stack<int>> f_stack;
    unordered_map<int ,int> freq;
    FreqStack() {
        f_stack.clear();
        max_freq=0;
    }
    
    void push(int val) {
        if(freq.find(val)==freq.end())
            freq[val]=0;
        freq[val]++;
        f_stack[freq[val]].push(val);
        max_freq=max(max_freq,freq[val]);
    }
    
    int pop() {
        int x=f_stack[max_freq].top();
        f_stack[max_freq].pop();
        freq[x]--;
        if(f_stack[max_freq].empty())
            max_freq--;
            
        return x;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */