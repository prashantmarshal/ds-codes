/*important stud*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define getenter scanf("\n");
#define For(i,s,l) for (int i = s; i < l; ++i)
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define scanarr(arr,n) For(i,0,n) scanf("%d",&arr[i])
#define scanarrlong(arr,n) For(i,0,n) scanf("%lld",&arr[i])


int main(int argc, char const *argv[])
{
	string s = "ABB";
	int l = s.length();

	int table[l][l];
	For(i,0,l){
		table[i][i] = 1;
		if(i+1<l)
		table[i][i+1] = (s[i]==s[i+1])?3:4;
	}

	For(len,3,l+1){
		For(i,0,l){
			int j = i+len-1;
			if(s[i] != s[i+1])
				table[i][j] = max(1+table[i+1][j],4+table[i+2][j]);
			else
				table[i][j] = max(1+table[i+1][j],3+table[i+2][j]);
		}
	}

	// For(i,0,l){
	// For(j,0,l)
	// cout<<table[i][j]<<" ";
	// cout<<endl;}
	cout<<table[0][l-1];
	return 0;
}