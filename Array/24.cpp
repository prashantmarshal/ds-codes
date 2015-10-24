/*Smallest subarray with sum greater than a given value*/

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int smallestsubarraylargersum(int *arr, int size, int sum){
	int curr_sum = 0;
	int start = 0, smallsubarray = size;
	int i = 0;
	while(i < size){
		if(curr_sum <= sum){
			curr_sum += arr[i++];
		}else{
			smallsubarray = min(i-start, smallsubarray);
			curr_sum -= arr[start];
			++start;

		}
	}
	return smallsubarray;

}

int main(){
	int arr[] = {1, 10, 5, 2, 7};	
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 9;
    cout<<smallestsubarraylargersum(arr, size, sum);
}