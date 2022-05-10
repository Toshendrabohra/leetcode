// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void preorder(int l, int r, vector<int> &ans , vector<int> &nums)
    {
        if(l>r)
        return;
        
        int mid=(l+r)/2;
        
        ans.push_back(nums[mid]);
        preorder(l, mid-1, ans, nums);
        preorder(mid+1 , r, ans, nums);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        int n=nums.size();
        vector<int> ans;
        
        preorder(0, n-1, ans, nums);
        
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends