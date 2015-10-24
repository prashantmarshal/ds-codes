/*Maximum of all subarrays of size k (Added a O(n) method)*/

#include <bits/stdc++.h>
using namespace std;
#define for(i,s,l) for(int i = s; i < l; ++i)

void solve(int arr[], int size)
{
	int dq[4];
	for(i,0,4)
		dq[i]=arr[i];
	sort(dq,dq+4);
	cout<<dq[3]<<" ";
	for(i,4,size)
	{
		if(arr[i]>dq[0]){
			dq[0]=arr[i];
			sort(dq,dq+4);
		}
		cout<<dq[3]<<" ";
	}
}

int main(int argc, char const *argv[])
{
	// int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
	int arr[] = {6, 5, 2, 3, 7, 4, 10, 11};
	int size=sizeof(arr)/sizeof(arr[0]);
	solve(arr,size);
	return 0;
}