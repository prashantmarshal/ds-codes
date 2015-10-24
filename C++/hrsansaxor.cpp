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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		For(i,0,n)
		cin>>arr[i];
		ll s[n];
		s[0] = arr[0];
		ll ans = s[0];
		For(i,1,n){
			s[i] = s[i-1];
			if((i+1)%2 == 1)
				s[i] ^= arr[i];
			ans = ans^s[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}