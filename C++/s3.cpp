#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define getenter scanf("\n");
#define For(i,s,l) for (int i = s; i < l; ++i)
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define scanarr(arr,n) For(i,0,n) scanf("%d",&arr[i])
#define scanarrlong(arr,n) For(i,0,n) scanf("%lld",&arr[i])

int ways(int N)
{
	int total_ways = 0;

	if (N == 1)
		return 1;

	For(i,1,N+1){
		if (i == 1 || i == N){
			total_ways = total_ways + ways(N - 1);
			total_ways = total_ways + 2;
		}else{
			total_ways = total_ways + ways(i - 1);
			total_ways = total_ways + ways(N - i);
			total_ways = total_ways + 1;
		}
	}
	return total_ways;
}

int main(int argc, char const *argv[])
{
	int T,x;
	cin>>T;
	while(T--){
		cin>>x;
		cout<<ways(x)<<endl;
		// cout<<abs(ways(x)-(x-1)*2)<<endl;		
	}
	return 0;
}