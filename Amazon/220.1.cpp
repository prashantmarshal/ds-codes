/*water trapped between buildings*/

#include <bits/stdc++.h>
using namespace std;
#define size(arr) sizeof(arr)/sizeof(arr[0])

void solve(int *arr, int len)
{
	int r[len];int l[len];

	l[0]=arr[0];r[len-1] = arr[len-1];
	for(int i=1; i<len; ++i)
		l[i]=max(l[i-1],arr[i]);

	for(int i=len-2; i>=0; --i)
		r[i]=max(r[i+1],arr[i]);

	int water=0;
	for (int i = 1; i < len-1; ++i)
		water += min(l[i], r[i]) - arr[i];
	printf("%d\n", water);
}

int main(int argc, char const *argv[])
{
	int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int l=size(arr);
	solve(arr,l);
	return 0;
}