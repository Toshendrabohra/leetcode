// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    string findAndReplace(string s ,int q, int index[], string sources[], string targets[]) {
        // code here
        vector<int> sorted[q] ;
        int n=s.size();
        
        for (int i = 0; i < q; i++)
        {
            sorted[i]={index[i], i};
        }
        sort(sorted,sorted+q);
        
        int poi_s=0;
        int poi_ans=0;
        int poi_ind=0;
        string ans;
        
        while(poi_s < n && poi_ind < q)
        {
            if(sorted[poi_ind][0]==poi_s)
            {
                int indx=sorted[poi_ind][1];
                string dum=s.substr(poi_s, sources[indx].size());
                if(dum==sources[indx])
                {
                    ans+=targets[indx];
                    poi_s+=sources[indx].size();
                }
                
                poi_ind++;
            }
            else if(poi_ind<q && sorted[poi_ind][0] < poi_s)
            {
                while(poi_ind<q && sorted[poi_ind][0] < poi_s)
                poi_ind++;
                
                
            }
            else if(poi_ind<q && sorted[poi_ind][0] > poi_s)
            {
                while(poi_s<n && sorted[poi_ind][0] > poi_s)
                ans+=s[poi_s],poi_s++;
            }
        }
        
        while(poi_s<n)
        ans+=s[poi_s++];
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends