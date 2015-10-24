/*reverse an array*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

void reversearray(int *arr, int size){
	int start = 0, end = size-1;
	while(start < end){
		arr[start] = arr[start]^arr[end];
		arr[end] = arr[start]^arr[end];
		arr[start] = arr[start]^arr[end];
		++start;
		--end;
	}

}

int main(){
	int arr[] = {3,2,7,10,5,9,6,7,8,4};
	int size = sizeof(arr)/sizeof(int);
	reversearray(arr, size);
	for (int i = 0; i < size; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}