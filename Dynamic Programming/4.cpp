/*Dynamic Programming | Set 3 (Longest Increasing Subsequence)*/


#include <iostream>
using namespace std;


int maximumof(int *L, int *arr, int j){
	int maximum = L[0];
	for (int i = 1; i <= j; ++i){
		if(L[i] >= maximum && arr[j+1] > arr[i])
			maximum = L[i];
	}
	return maximum;
}

int listrecursion(int *arr, int n){
	if(n == 0)
		return 1;
	return max(L, arr, n-1);
}

int lis(int *arr, int size){
	int L[size];
	L[0] = 1;
	int maxtillnow = L[0];
	for(int i = 1; i < size; ++i){
		L[i] = 1 + maximumof(L, arr, i-1);
		if(maxtillnow < L[i])
			maxtillnow = L[i];
	}
	return maxtillnow;
}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<lis(arr, size);
    return 0;
}

