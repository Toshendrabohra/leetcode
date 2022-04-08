class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n=arr.size()-1;
        for(int i=0;i<=n;i++){

int cnt=0;
        while(  arr[arr[i]-1]!=arr[i]){
            cnt++;
            swap(arr[i],arr[arr[i]-1]);
              

        }
       // cout<<cnt<<endl;

}
int ans=-1;
for(int i=0;i<=n;i++){

    if(arr[i]!=i+1) {
        ans=arr[i];
        break;
    }

}
return ans;

    
    }
};
