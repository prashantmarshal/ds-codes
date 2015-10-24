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
#define ll long long int
#define max(a,b,c) (max(max(a,b),c))


void solve(){
	string s;
	cin>>s;
	int l = s.length();
	int i = 0,j = l-1;
	int count = 0;
	while(i < j){
		if(s[i] != s[j])
			count+= abs(s[i]-s[j]);
		i++;j--;
	}

	pi(count);printf("\n");
}
int main(int argc, char const *argv[])
{
	int T;
	si(T);
	while(T--)
		solve();
	return 0;
}