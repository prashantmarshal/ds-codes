/*Maximum difference between two elements such that larger element appears after the smaller number*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


int maxdiff(int *arr, int size){
	int min_number=arr[0], max_diff=arr[1]-arr[0];

	for(int i = 0; i < size; i++){
		if(arr[i] < min_number)
			min_number = arr[i];
		if(arr[i]-min_number > max_diff)
			max_diff = arr[i]-min_number;
	}
	return max_diff;
}

int maxdiffanother(int *arr, int size){ // converting into maximum sum subarray problem
	int *arr2 = new int[size-1];
	for (int i = 0; i < size-1; ++i){
		arr2[i] = arr[i+1]-arr[i];
	}

	int max_sum = arr2[0]; int result = 0;
	for (int i = 1; i < size-1; ++i){
		max_sum = max(max_sum+arr2[i], arr2[i]);
		result = max(result, max_sum);
	}
	return result;

}

int main(){
	int arr[] = {7,5,8,3,10};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<maxdiffanother(arr, size);
}