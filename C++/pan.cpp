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


bool checkchars(string s, int st, int l){
	For(i,st,l+1){
		if(s[i] >= 'A' && s[i] <= 'Z')
			continue;
		else
			return false;
	}
	return true;
}

bool checkdigits(string s, int st, int l){
	For(i,st,l+1){
		if(s[i] >= '0' && s[i] <= '9')
			continue;
		else
			return false;
	}
	return true;
}

void solve(){
	string s;
	cin>>s;
	if(s.length()!=10 || !checkchars(s,0,4) || !checkdigits(s,5,8) || !checkchars(s,9,9)){
		printf("NO\n");
		return;
	}else{
		printf("YES\n");
	}
}
int main(int argc, char const *argv[])
{
	int T;
	si(T);
	while(T--)
		solve();
	return 0;
}