/*check for majority in an array*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


bool isMajority(int *arr, int size){
	int offset = (size%2)?(size/2+1):size/2;
	for(int i = 0; i < offset; ++i){
		if(arr[i] == arr[i+offset-1]){
			return true;
		}
	}
	return false;
}
int main(){
	int arr[] ={1, 2, 3, 4, 4, 4, 4};
	int size = sizeof(arr)/sizeof(arr[0]);
	if (isMajority(arr, size))
		printf("Yes.\n");
	else
		printf("No.\n");
	return 0;
}

