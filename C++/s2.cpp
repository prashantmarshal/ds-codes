#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%lld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%lld", i);
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define scanarr(arr,n) For(i,0,n) si(arr[i])
#define scanarrlong(arr,n) For(i,0,n) sl(arr[i])
#define ll long long int
#define getenter scanf("\n");


void solve(){
	int n;
	cin>>n;
	int arr[n];
	scanarr(arr,n);

	int mid = n/2;
	int pn=0,bn=0,a,b,c,d;
    int tot = 0;
    For(i,1,mid){
		if(arr[i-1]%2 == 0 && arr[i+1]%2 == 0)
			pn = (arr[i-1]+arr[i+1])/2;
		else
			pn = arr[i];

		if(arr[n-1-i-1]%2 == 0 && arr[n-1-i+1]%2  == 0)
			bn =(arr[n-1-i-1]+arr[n-1-i+1])/2;
		else
			bn = arr[i];

		a = abs(pn-bn);
		b = abs(pn-arr[n-1-i]);
		c = abs(arr[i]-bn);
		d = abs(arr[i]-arr[n-1-i]);
		a = max(a,b);
		c = max(c,d);
		tot += max(a,c);

	}

	tot = tot+abs((arr[0]-arr[n-1]));

	pi(tot);printf("\n");
}

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
