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

bool isdone(char c){
	if(c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string str;
	
	map<string, int> hash;
	getenter;	
	while(n--){

		string line;
		getline(cin,line);

		int linel = line.length();
		string temp = "";

		For(j,0,linel)	
		if(isdone(line[j]))	temp += line[j];
		else{
			if(temp.length() > 0)
			hash[temp]++;
			temp = "";
		}
		
		if(temp.length() > 0)
			hash[temp]++;
	}

	int t;
	cin>>t;

	while(t--){
		string word;
		cin>>word;
		pi(hash[word]);printf("\n");
	}

	hash.clear();

	return 0;
}