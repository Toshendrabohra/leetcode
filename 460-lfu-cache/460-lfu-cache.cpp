class LFUCache {
public:
    struct node
    {
        int key;
        int value;
        int freq;
        node *prev,*next;
        node(int k,int v)
        {
            freq=1;
            key=k;value=v;
                prev=NULL;
                next=NULL;
        }
    };
    
    int size,counter,cur_size,min_freq;
    unordered_map<int,node*> mapp;
    unordered_map<int,pair<node*,node*>> freq_list;

    LFUCache(int capacity) {
        size=capacity;counter=1;cur_size=0;
        min_freq=1;
        mapp.clear();
        freq_list.clear();
    }
    void remove(int key)
    {
        node *temp=mapp[key];
        cur_size--;
        mapp.erase(key);
        if(temp->next==NULL && temp->prev==NULL)
        {
            if(min_freq==temp->freq)
                min_freq++;
            freq_list.erase(temp->freq);
            
        }
        else if(temp->next==NULL)
        {
            temp->prev->next=NULL;
            freq_list[temp->freq].second=temp->prev;
        }
        else if(temp->prev==NULL)
        {
            temp->next->prev=NULL;
            freq_list[temp->freq].first=temp->next;
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
    }
    void add(int key,int val,int freq)
    {
        cur_size++;
        min_freq=min(min_freq,freq);
        node *fresher=new node(key,val);
        fresher->freq=freq;
        if(freq_list.find(freq)==freq_list.end())
        { 
            freq_list[freq]={fresher,fresher};
        }
        else
        {
            fresher->prev=freq_list[freq].second;
            freq_list[freq].second->next=fresher;
            freq_list[freq].second=fresher;
        }
        mapp[key]=fresher;
    }
    int get(int key) {
        if(mapp.find(key)!=mapp.end())
        {
            node *temp=mapp[key];
            remove(temp->key);
            add(temp->key,temp->value,temp->freq+1);
           return mapp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(size==0)
            return;
        if(mapp.find(key)!=mapp.end())
        {
            node *temp=mapp[key];
            remove(temp->key);
            add(temp->key,value,temp->freq+1);
         //  return mapp[key]->value;
        }
        else
        {
           // cout<<key<<" "<<min_freq<<endl;
           if(cur_size>=size) 
              remove(freq_list[min_freq].first->key);
           add(key,value,1);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */