/*water trapped between buildings*/


#include <bits/stdc++.h>
using namespace std;
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])


int solve(int arr[], int size){
	int left[size],right[size];
	left[0]=arr[0]; right[size-1]=arr[size-1];

	for(int i=1; i<size; ++i){
		left[i] = max(left[i-1],arr[i]);
	}
	for(int i=size-2; i>=0; --i){
		right[i] = max(right[i+1],arr[i]);
	}
	int sum=0;
	for(int i=1; i<size-1; ++i){
		sum += min(left[i],right[i])-arr[i];
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int size = SIZE(arr);
	cout<<solve(arr,size);
	return 0;
}