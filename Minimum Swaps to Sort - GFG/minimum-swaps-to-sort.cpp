// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<int> hash(1e6+1);
	    int n=nums.size();
	    vector<int> dum=nums;
	     sort(dum.begin(),dum.end());
	     for(int i=0;i<n;i++)
	    {
	        hash[dum[i]]=i;
	    }
	   
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        
	        int cnt=0;
	        if(dum[i]!=nums[i])
	        {
	            int cur=i;
	            do
	            {
	                cnt++;
	                swap(nums[i],nums[hash[nums[i]]]);
	            }
	            while(hash[nums[i]]!=i);
	        }
	        ans+=cnt;
	    }
	    return ans;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends