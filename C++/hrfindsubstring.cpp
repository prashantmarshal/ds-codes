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
#define getenter scanf("\n")

bool check(string s, int one, int two){
	if((s[one] >= 'a' && s[one] <= 'z') || (s[one] >= 'A' && s[one] <= 'Z') || (s[one] == '_'))
		if((s[two] >= 'a' && s[two] <= 'z') || (s[two] >= 'A' && s[two] <= 'Z') || (s[two] == '_'))	
			return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int t,l,start,count,i=0,i2;
	cin>>t;
	string s[100];
	getenter;
	while(t--){
		getline(cin,s[i]);
		i++;
	}
	int x;
	cin>>x;
	getenter;
	while(x--){
		string word;
		cin>>word;
		int wl = word.size();
		start =0;count= 0,i2=i;
		while(i2--){
			l = s[i2].length();
			while(1){
				start = s[i2].find(word,start+1);
				if( start != -1)
				{
					if(start > 0 && start < l-wl){
						if(check(s[i2],start-1,start+wl)){
							++count;
						}
					}
				}else
				break;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}