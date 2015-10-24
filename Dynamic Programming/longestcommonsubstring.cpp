#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define pi(i) printf("%d", i)
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])


int longestcommonsubstring(string s1, string s2){
	int l1=s1.length(),l2=s2.length();

	int t[l1+1][l2+1];
	For(i,0,l1+1)
		t[i][0]=0;
	For(i,0,l2+1)
		t[0][i]=0;
	int maxi = 0;
	For(i,1,l1+1)
	For(j,1,l2+1)
	{
		t[i][j] = (s1[i-1]==s2[j-1])?t[i-1][j-1]+1:0;
		maxi=max(maxi,t[i][j]);
	}

	int a,b;
	For(i,0,l1+1)
	For(j,0,l2+1)
	if(t[i][j] == maxi){
		a=i;
		b=j;
	}
	For(i,a-maxi,a)
	printf("%c", s1[i]);
	printf("\n");

	return maxi;
}

int main(int argc, char const *argv[])
{
	string s1 = "chootmeindanda";
	string s2 = "terichootmeinlund";
	pi(longestcommonsubstring(s1,s2));
	return 0;
}