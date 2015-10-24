#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maximumof(int *ar, int *arr, int index, int curr){
	int max = 0;
	for (int i = 0; i <= index; ++i)
		if(arr[i] > max && ar[i] < ar[curr])
			max = arr[i];
	return max;
}

int maximumof2(int *ar, int *arr, int index, int curr, int size){
	int max = 0;
	for (int i = size-1; i >= index; --i){
		if(arr[i] > max && ar[i] < ar[curr])
			max = arr[i];
	}
	return max;
}

int maxsubsequence(int *arr, int size){
	int L[size];
	L[0] = 1;
	int maxoflj = L[0], maxtillnow = L[0];

	for(int i = 1; i < size; ++i){
		L[i] = 1+maximumof(arr, L, i-1, i);
		maxtillnow = max(L[i], maxtillnow);
	}

	int L2[size];
	L2[size-1] = 1;

	int maxoflj2 = L2[size-1], maxtillnow2 = L2[size-1];
	

	for(int i = size-2; i >= 0; --i){
		L2[i] = 1+maximumof2(arr, L2, i+1, i, size);
		maxtillnow2 = max(L2[i], maxtillnow2);
	}

	int result = 0;
	for (int i = 0; i < size; ++i)
		if(result < L[i]+L2[i])
			result = L[i]+L2[i]-1;

	for (int i = 0; i < size; ++i)
		cout<<L[i]<<" ";
	cout<<endl;
	for (int i = 0; i < size; ++i)
		cout<<L2[i]<<" ";
	cout<<endl;
	
	return result;

}

int main(){
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15,656,546,4,8465, 2132,132,121,215,1651,212,121,21,11,12,121,51,9,9,5};
	int size = sizeof(arr)/sizeof(arr[0]);
    cout<<maxsubsequence(arr, size);

}


