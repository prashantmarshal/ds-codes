/*equilibrium index of an array*/

#include <iostream>
#include <stdio.h>
#include <climits>
#include <cmath>
using namespace std;


int equilibriumindex(int *arr, int size){
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += arr[i];
	int leftsum = 0;
	for (int i = 0; i < size; ++i){
		if((sum-arr[i])/2 == leftsum)
			return arr[i];
		else{
			leftsum += arr[i];
		}
	}
}

int main(){
	int arr[] = {-7, 1, 5, 1, -4, 3, 0};
	int size = sizeof(arr)/sizeof(int);
	cout<<equilibriumindex(arr, size);

}