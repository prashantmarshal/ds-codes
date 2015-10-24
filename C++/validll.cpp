#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define scanarr(arr,n) For(i,0,n) si(arr[i])
#define scanarrlong(arr,n) For(i,0,n) sl(arr[i])
#define ull unsigned long long int
#define getenter scanf("\n")

bool checknumber(string s,int start, int last){
	bool flag = true;
	int dot;
	For(i,start,last+1){
		if(s[i] == '.' && flag){
			dot = i;
			flag=false;
		}
		else if(s[i] == '.' && flag == false)
			return false;
	}

	For(i,start,last+1)
	if(i == start && (s[i] == '+' || s[i] == '-')){
		continue;
	}
	else{
		if(i != dot)
		if(!isdigit(s[i]))
		return false;
	}
	// now converting to number
	if(s[start] == '+' || s[start] == '-')
	start++;
	if(s[start] == '0' && s[start+1] >= '0' && s[start+1] <= '9')
		return false;    

	string s2 = s.substr(start,dot-start);
	if(s2.length()>3)
		return false;
	if(s2.length()==3)
		if(s2 > "180")
			return false;
	if(s2.length() == 0)
		return false;

	s2 = s.substr(dot+1,last-dot);
	
	return true;
	
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	getenter;
	while(t--){
		string s;
		getline(cin,s);
		int comma = s.find(',',1);
		if(checknumber(s,1,comma-1)){
			if(checknumber(s,comma+2,s.length()-2))
				cout<<"Valid\n";
		}else{
			cout<<"Invalid\n";
		}
	}
	return 0;
}