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
#define ull unsigned long long int
#define max(a,b,c) (max(max(a,b),c))
#define getenter scanf("\n")

ull convert(){
	ull ans = 0;
	For(i,0,32){
		ans += pow(2.0,i);
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	ull flip = convert();
	cout<<flip<<endl;
	while(t--){
		ull x;
		cin>>x;
		cout<<(x^flip)<<endl;
	}
	return 0;
}