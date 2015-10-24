/*Minimum number of jumps to reach end*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)


int minjumps(int *arr, int l, int h){
	if(l == h) // no jumps required
		return 0;

	if(arr[l] == 0)
		return INT_MAX;

	int minjump = INT_MAX;
	for(int i = l+1; i <= l+arr[l] && i <= h; ++i){
		int currjump = minjumps(arr, i, h);
		if(currjump != INT_MAX && currjump+1 < minjump)
			minjump = currjump+1;
	}

	return minjump;
	
}

int minjumpsdp(int arr[], int size){
	int t[size+1];
	for(int i = 0; i < size+1; ++i)
		t[i] = 0;
	// t[0] = 1;


	for(int i = 1; i < size+1; ++i){
		int res = 10000;
		for(int j = 0; j < i; ++j){
			if(i-j <= arr[j])
				res = min(res,t[j]+1);
		}
		t[i] = res;
		// cout<<t[i]<<" ";
	}

	return t[size];


}


int main(){
	int arr[] = {1,3,2,5,6,4,7,8,9,6,5,4,7,8,5,6,3,2,1,5,4,6,8,9,5,8,9,6,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<minjumps(arr,0,n-1)<<endl;
	cout<<minjumpsdp(arr, n);
}