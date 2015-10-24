/*find missing number*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int absentnumber(int *arr, int size){
	int xor1 = 0;
	for (int i = 0; i < size; ++i){
		xor1 = xor1^arr[i];
	}

	int xor2 = 0;
	for (int i = 0; i < size+1; ++i){
		xor2 = xor2^(i+1);
	}

	return xor1^xor2;

}

int main(){
	int arr[] = {1,2,4,5,6};
	int size = sizeof(arr)/sizeof(int);
	cout<<absentnumber(arr, size);
}