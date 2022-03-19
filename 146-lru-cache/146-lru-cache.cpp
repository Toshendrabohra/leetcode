class LRUCache {
public:
    deque<pair<int,int>> LRU;
    unordered_map<int ,int> key_val;
    unordered_map<int ,int> status;
    int size,cur_size,counter;
    LRUCache(int capacity) {
        size=capacity;
        key_val.clear();
        status.clear();
        cur_size=0;
        counter=1;
        LRU.clear();
    }
    
    int get(int key) {
        
        if(key_val.find(key)!=key_val.end())
        {
            status[key]=counter++;
            LRU.push_back({key,status[key]});
            while(status[LRU.front().first]!=LRU.front().second)
            {
                LRU.pop_front();
            }
            
        return key_val[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(key_val.find(key)==key_val.end())
        {
            cur_size++;
        }
        key_val[key]=value;
        status[key]=counter++;
        LRU.push_back({key,status[key]});
        while(status[LRU.front().first]!=LRU.front().second)
            {
                LRU.pop_front();
            }
        if(cur_size>size)
        {
            //cout<<LRU.front().first<<" ";
            key_val.erase(LRU.front().first);
            LRU.pop_front();
            cur_size--;
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */