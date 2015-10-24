#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define scanarr(arr,n) For(i,0,n) si(arr[i])
#define scanarrlong(arr,n) For(i,0,n) sl(arr[i])
#define ll long long int
#define getenter scanf("\n")

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--){
		ll x,k,ans=0;
        cin>>x>>k;
		ll arr[x], prefix[x],count[k];
		memset(count,0,sizeof(count));
		cin>>arr[0];
		prefix[0] = arr[0];
		count[prefix[0]%k]++;
		For(i,1,x)
		{
			cin>>arr[i];
			prefix[i] = (prefix[i-1]+arr[i])%k;
			count[prefix[i]%k]++;
		}

		For(i,0,k){
			ans += count[i]*(count[i]-1)/2;
		}
		ans += count[0];
		cout<<ans<<endl;
	}
	return 0;
}