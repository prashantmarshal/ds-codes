/*Maximum Sum Increasing Subsequence*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>
using namespace std;


int maximumof(int *ar, int *arr, int index, int curr){
	int max = 0;
	for(int i = 0; i <= index; ++i){
		if(max < arr[i] && ar[i] < ar[curr]){
			max = arr[i];
		}
	}

	return max;
}

int maxsumlis(int *arr, int size){
	int L[size];
	L[0] = arr[0];
	int maxoflj = L[0], maxtillnow = L[0];
	// cout<<L[0]<<endl;
	for (int i = 1; i < size; ++i){
		L[i] = arr[i] + maximumof(arr, L, i-1, i);
		maxtillnow = max(maxtillnow, L[i]);
		cout<<L[i]<<" ";
	}
	cout<<endl;
	int index;
	for(int i = 0; i < size; ++i){
		if(L[i] == maxtillnow)
			index = i;
	}
	// i has the maximum sum value last element
	// to print the taken values
	int index2 = index;
	while(index2){
		if(L[index2]-arr[index2] == L[index2-1]){
			cout<<arr[index]<<" ";
			index--;
		}
		index2--;
		
	}


	return maxtillnow;
}

int main(){
	int arr[] = { 10, 22, 11, 9, 10, 12, 13};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("Maximum Sum Increasing Subsequence is %d\n", maxsumlis(arr, size));
}