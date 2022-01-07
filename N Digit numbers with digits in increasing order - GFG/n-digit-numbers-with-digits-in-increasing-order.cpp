// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void make_num(vector<int> &ans,int cur,int n,int num,int len)
    {
        if(len==n)
        {
            ans.push_back(num);
            return ;
        }
        for(int i=cur;i<=10-(n-len);i++)
        {
            num*=10;
            num+=i;
            make_num(ans,i+1,n,num,len+1);
            num/=10;
        }
    }
    vector<int> increasingNumbers(int N)
    {
        // Write Your Code here
        vector<int> ans;
        if(N==1)
        ans.push_back(0);
        int num=0;
         make_num(ans,1,N,num,0);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends