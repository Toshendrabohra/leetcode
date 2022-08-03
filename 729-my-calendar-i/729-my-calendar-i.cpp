class MyCalendar {
public:
    set<vector<int>> s,e;
    MyCalendar() {
       
    }
    
    bool book(int start, int end) {
        if(!s.empty())
        {
            auto next = s.lower_bound({start,0});
            auto prev = e.lower_bound({-start,0});
            
        if(next!=s.end())
            if((*next)[0] == start || end > (*next)[0] )
                return false;
            
        if(prev!=e.end())
            {
                
                if(start < (*prev)[1])
                    return false;
            }
        }
        s.insert({start, end});
        e.insert({-start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */