/*check if array elements are consecutive*/

#include <iostream>
#include <stdio.h>
#include <climits>
#include <cmath>
using namespace std;

bool checkrepetition(int *arr, int size){
	for(int i = 0; i < size; ++i){
		int element = abs(arr[i]);
		if(arr[element] > 0)
			arr[element] = -arr[element];
		else if(arr[element] < 0){
			return false;
		}
	}
	return true;
}

bool checkconsecutive(int *arr, int size){
	if(checkrepetition(arr, size)){
		int min = INT_MAX, max = INT_MIN;
		for (int i = 0; i < size; ++i){
			if(abs(arr[i]) < min)
				min = abs(arr[i]);
			if(abs(arr[i]) > max)
				max = abs(arr[i]);
		}
		if(max-min+1 == size)
			return true;
		else return false;
	}else {
		return false;
	}

}


int main(){
	int arr[] = {2,6,4,7,8,9,5,3,1};
	int size = sizeof(arr)/sizeof(int);
	if(checkconsecutive(arr, size))
		printf("Yes.\n");
	else
		printf("No.\n");
}