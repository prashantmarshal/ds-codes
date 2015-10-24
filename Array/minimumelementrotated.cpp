/*pivoted array*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;



int pivotedarray(int *arr, int number, int low, int high){
	if(low > high)
		return -1;
	int mid = (low+high+1)/2;

	if(number > arr[mid]){
		if(arr[mid] > arr[high]){
			pivotedarray(arr, number, mid+1, high);
		}else if(arr[mid] <= arr[high]){
			if(number > arr[high])
				pivotedarray(arr, number, low, mid-1);
			else
				pivotedarray(arr, number, mid+1, high);
		}else
			return mid;

	}else if(number < arr[mid]){
		if(arr[mid] < arr[low])
			pivotedarray(arr, number, low, mid-1);
		else if(arr[mid] >= arr[low]){
			if(number >= arr[low])
				pivotedarray(arr, number, low, mid-1);
			else
				pivotedarray(arr, number, mid+1, high);
		}

	}else{
		return mid;
	}
}

int main(){
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int size = sizeof(arr)/sizeof(int);
	int number;
	for (int i = 0; i < size; ++i){
		number = arr[i];
		cout<<pivotedarray(arr, number, 0, size-1)<<" ";
	}

}