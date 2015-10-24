#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%lld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%lld", i);
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define sa(arr,n) For(i,0,n) si(arr[i])
#define salong(arr,n) For(i,0,n) sl(arr[i])
#define salongl(arr,n) for(int i = n-1; i >= 0; --i) sl(arr[i])
#define ll long long int
#define max(a,b,c) (max(max(a,b),c))

void solve(){
	int N;
	si(N);
	ll *arr = new ll[N];
	salongl(arr,N);

	ll sumarray[N];
	sumarray[0] = arr[0];
	For(i,1,N){
		sumarray[i] = sumarray[i-1]+arr[i];
	}

	ll dp[N];
	For(i,0,N)
	dp[i] = -1000000000;
	
	dp[0] = arr[0];
	dp[1] = arr[0]+arr[1];
	dp[2] = arr[0]+arr[1]+arr[2];

	For(i,3,N){
		dp[i] = max(sumarray[i]-dp[i-1],sumarray[i]-dp[i-2],sumarray[i]-dp[i-3]);
	}

	pl(dp[N-1]);printf("\n");



}

int main(int argc, char const *argv[])
{
	int T;
	si(T);
	while(T--)
	solve();
	return 0;
}