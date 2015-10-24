/*Longest Increasing Subsequence*/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>
using namespace std;

int maximumof(int *ar, int *arr, int index, int curr){
	int max = 0;
	for (int i = 0; i <= index; ++i)
		if(arr[i] > max && ar[i] < ar[curr])
			max = arr[i];
	return max;
}

int lis(int *arr, int size){
	int L[size];
	L[0] = 1;
	int maxoflj = L[0], maxtillnow = L[0];
	cout<<L[0]<<endl;
	for (int i = 1; i < size; ++i){
		L[i] = 1+maximumof(arr, L, i-1, i);
		cout<<L[i]<<endl;
		maxtillnow = max(maxtillnow, L[i]);
	}

	return maxtillnow;

}

int main(){
	int arr[] = { 10, 22, 5, 9, 10, 11, 12};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("Length of LIS is %d\n", lis(arr, size));
}	