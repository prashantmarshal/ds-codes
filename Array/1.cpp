/*Given an array A[] and a number x, check for pair in A[] with sum as x*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


bool findpair(int *arr, int x, int size){
	int start = 0, end = size-1;
	while(start < end){
		int currsum = arr[start]+arr[end];
		if(currsum == x){
			return true;
		}
		if(currsum < x)
			start++;
		else
			end--;
	}
	return false;
}


int main(){

	int arr[] = {1, 4, 45, 6, 10, -8};
	int size = sizeof(arr)/sizeof(int);
	sort(arr, arr+size);
	int x;
	cout<<"Enter x : ";
	cin>>x;
	if(findpair(arr, x, size))
		cout<<"Yes\n";
	else
		cout<<"No\n";
}