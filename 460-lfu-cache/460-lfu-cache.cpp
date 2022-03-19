class LFUCache {
public:
    int size,counter,cur_size;
    set<vector<int>> LFU;
    unordered_map<int,int> status;
    unordered_map<int,int> count;
    unordered_map<int,int> Key;
    LFUCache(int capacity) {
        size=capacity;counter=1;cur_size=0;
        LFU.clear();
        status.clear();
        count.clear();
        Key.clear();
    }
    
    int get(int key) {
        if(Key.find(key)!=Key.end())
        {
            LFU.erase({count[key],status[key],key});
            count[key]++;
            status[key]=counter++;
            LFU.insert({count[key],status[key],key});
            return Key[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(Key.find(key)!=Key.end())
        {
            LFU.erase({count[key],status[key],key});
            count[key]++;
            status[key]=counter++;
            Key[key]=value;
            LFU.insert({count[key],status[key],key});
        }
        else
        {
            if(size==0)
                return;
            
            if(size<=cur_size)
        {
                
            cur_size--;
            int lfu_key=(*LFU.begin())[2];
            cout<<lfu_key<<" ";
            LFU.erase(LFU.begin());
            count[lfu_key]=0;
            status.erase(lfu_key);
            Key.erase(lfu_key);
        }
            count[key]++;
            cur_size++;
            status[key]=counter++;
            Key[key]=value;
            LFU.insert({count[key],status[key],key});
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */