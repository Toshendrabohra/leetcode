// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    char profession(int level, int pos){
        // code here
        if( pos == 1)
        return 'e';
        char c = profession(level, (pos - 1)/2 + 1);
       
        if((pos - 1)%2  == 0)
        {
            if(c =='e')
                return 'e';
            else 
                return 'd';
        }
        else
        {
           
            if(c=='d')
                return 'e';
            else 
            {
                return 'd';
            }
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends