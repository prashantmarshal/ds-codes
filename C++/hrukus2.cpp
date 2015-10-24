/*important*/

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

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	getenter;
	std::map<string, int> hash;
	std::map<string, int> hash2;
	while(t--){
		string s;
		getline(cin,s);
		int l = s.length();
		string temp = "";

		For(i,0,l){
			if(s[i] != ' ')
				temp += s[i];
			else{
				if(temp.find("our") != -1)
					hash[temp]++;
				else if(temp.find("or") != -1)
					hash2[temp]++;
				temp = "";
			}
		}

		if(temp.length()>0){
			if(temp.find("our") != -1)
				hash[temp]++;
			else if(temp.find("or") != -1)
				hash2[temp]++;
		}
	}

	int tt,count;
	cin>>tt;
	while(tt--){
		string key;
		cin>>key;
		int index = 0, count = hash[key];
		while(true){
			index = key.find("our", index);
			if(index==-1)
				break;
			key.replace(index,3,"or");
			index += 2;
		}
		count += hash2[key];
			cout<<count<<endl;
	}
	
	return 0;
}

/*
stringstream ss("bla bla");
string s;

while (getline(ss, s, ' ')) {
 cout << s << endl;
}
*/