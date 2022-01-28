// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define ll int64_t
const int mod=1000003;
ll expo(ll a,ll b){
    a%=mod;
    ll ans=1;
    while(b){
        if(b&1)(ans*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return ans;
}
vector<ll> fact,ifact;
void pre(){
    fact.resize(mod+1);
    ifact.resize(mod+1);
    fact[0]=fact[1]=1;
    ifact[0]=ifact[1]=expo(1,mod-2);
    for(int i=2;i<=mod;i++)(fact[i]=i*fact[i-1])%=mod,ifact[i]=expo(fact[i],mod-2);
}
bool f=0;
class Solution {
public:
int nCr(long long n, long long r) {
    // Code here
     if(f==0)pre(),f=1;
    ll ans=1;
    // r=max(r,n-r);
    while(n&&r){
        int a=n%mod,b=r%mod;
        n/=mod,r/=mod;
        if(a<b){
            return 0;
        }
        else (ans*=(fact[a]*(ifact[b]*ifact[a-b])%mod)%mod)%=mod;
    }
    (ans*=(fact[n]*(ifact[r]*ifact[n-r])%mod)%mod)%=mod;
    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long n, r;
		cin >> n >> r;
		Solution obj;
		int ans = obj.nCr(n, r);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends