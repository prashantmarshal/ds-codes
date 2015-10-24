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


bool checkforarrayipv4(string arr[4]){
	For(i,0,4){
		if((arr[i] > "255" && arr[i].length() >= 3) || arr[i].length() > 3)
			return false;
	return true;
}

bool checkforarrayipv6(string arr[8]){
	For(i,0,8){
		int l = arr[i].length();
		For(j,0,l){
			if((arr[i][j] >= '0' && arr[i][j] <= '9') || (arr[i][j] >= 'a' && arr[i][j] <= 'f'))
				continue;
			else
				return false;
		}
	}
	return true;
}

bool isipv4(string s){
	char dot = '.';
	int len = s.length();
	
	int cnt = 0;
	For(i,0,len)
	if(s[i] == dot)
		cnt++;
	if(cnt!=3)
		return false;
	
	string arr[4];
	For(i,0,4)
	arr[i] = "";	
	int t = 0;
	For(i,0,len){
		if(s[i]!=dot)
			arr[t] += s[i];
		else if(s[i] == dot)
			t++;
	}

	For(i,0,4)
	if(arr[i] == "")
		return false;
	return checkforarrayipv4(arr);
}

bool isipv6(string s){
	char colon = ':';
	int len = s.length();
	int cnt = 0;
	For(i,0,len)
	if(s[i] == colon)
		cnt++;
	if(cnt!=7)
		return false;
	string arr[8];
	For(i,0,8)
	arr[i] = "";

	int t = 0;

	For(i,0,len){

		if(s[i]!=colon)
			arr[t] += s[i];
		else if(s[i] == colon)
			t++;
	}

	For(i,0,8)
	if(arr[i] == "")
		return false;
	return checkforarrayipv6(arr);

}

void solve(){
	string s;
	scanf("\n");
	getline(cin,s);
	if(isipv4(s))
		printf("IPv4\n");
	else if(isipv6(s))
		printf("IPv6\n");
	else
		printf("Neither\n");
}

int main(int argc, char const *argv[])
{
	int T;
	si(T);
	while(T--)
		solve();
	return 0;
}