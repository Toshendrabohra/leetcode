class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(b[1] == a[1])
            return a[0] < b[0];
        
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
       
        sort(courses.begin(), courses.end(), comp);
        int tot = 0;
        priority_queue<int> p;
        
        for( int i = 0; i < courses.size(); i++)
        {
            if(tot + courses[i][0] <= courses[i][1])    
            {
                p.push(courses[i][0]);
                tot += courses[i][0];
            }
            else if(!p.empty())
            {
                
                 tot += courses[i][0];
                 p.push(courses[i][0]);
                 tot -= p.top();
                 p.pop();
                
            }
          //  cout<<(tot)<<" ";
        }
        
        
        return p.size();
        
    }
};