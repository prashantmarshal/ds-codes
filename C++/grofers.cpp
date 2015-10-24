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
	int arr[6][5] = {
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	};
	int rows = sizeof(arr)/sizeof(arr[0]);
	int cols = sizeof(arr[0])/sizeof(arr[0][0]);
	cout<<rows<<" "<<cols<<endl;
	return 0;
}