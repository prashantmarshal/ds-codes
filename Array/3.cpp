/*largest sum contiguous array*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


int maxsumsubarray(int *arr, int size){ // dynamic programming
	int maxsum = arr[0];
	int max_so_far = maxsum;

	for (int i = 1; i < size; ++i){
		maxsum = max(maxsum+arr[i], arr[i]); // either the window from previous plus current element or just ththe current element
		max_so_far = max(maxsum, max_so_far);
	}

	return max_so_far;

}


int main(){
	int arr[] = {14, -1, 2, -8, 4, -1, -2, 1, 5, -3};
	int size = sizeof(arr)/sizeof(int);
	cout<<maxsumsubarray(arr, size);
}