/*Maximum sum such that no two elements are adjacent*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


int maxsum(int *arr, int size){
	int incl = arr[0], excl = 0;
	int temp;
	for (int i = 1; i < size; ++i){
		temp = max(arr[i]+excl, incl);
		excl = incl;
		incl = temp;
	}
	return temp;
}


int main(){
	int arr[] = {3,2,7,10};
	int size = sizeof(arr)/sizeof(int);
	cout<<maxsum(arr, size);
}