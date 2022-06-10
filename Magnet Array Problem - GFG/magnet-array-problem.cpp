// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void find(int n, int x, double a[], double getAnswer[])
    {
        double l = a[x], r = a[x + 1];
        
        while( l < r)
        {
            double mid = (l+r)/2.0;
            double left = 0, right = 0;
            for (int i = 0; i < n; i++)
            {
                if(i<=x)
                {
                    left += 1.0/(mid - a[i]);
                }
                else
                right += 1.0/(a[i] -  mid);
            }
            
            if( abs(left - right ) <= 1e-12)
            {
                getAnswer[x] = mid;
                
                return;
            }
            else if( left > right)
            {
                l = mid;
            }
            else
            r = mid;
          //  cout<<mid<<" ";
        }
    
   // cout<<endl;
    }
    
    
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        // Your code goes here   
        for (int i = 0; i < n-1; i++ )
        {
            find(n, i, magnets, getAnswer);
        }
       // cout<<endl;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends