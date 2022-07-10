// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    int indx = n-1;
    vector<int> ans(n);
    sort(a,a+n);
    for( int i = 0; i < n ; i +=2)
    {
        ans[i] = a[indx--];
    }
    indx = 0;
    for(int i = 1; i < n; i+=2)
    {
        ans[i] = a[indx++] ;
    }
    indx = 0;
    for( int i = 0; i < n; i++)
    {
        if(i%2==0)
        indx+=ans[i];
        else
        indx-=ans[i];
        if(indx == 0)
        return {-1};
    }
    
    return ans;
    
    
}
