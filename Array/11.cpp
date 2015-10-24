
/*counting number of occurrences of a number in a sorted array*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int size;
int first(int *arr, int low, int high, int number){
	if(low > high)
		return -1;
	int mid = (low+high+1)/2;
	if(arr[mid] == number && (mid == 0 || number > arr[mid-1]))
		return mid;
	else if(arr[mid] < number)
		return first(arr, mid+1, high, number);
	else if(arr[mid] >= number)
		return first(arr, low, mid-1, number);
	return -1;
}

int second(int *arr, int low, int high, int number){
	if(low > high)
		return -1;
	int mid = (low+high+1)/2;
	if(arr[mid] == number && (mid == size-1 || number < arr[mid+1]))
		return mid;
	else if(arr[mid] <= number){
		return second(arr, mid+1, high, number);
	}
	else if(arr[mid] > number)
		return second(arr, low, mid-1, number);
	return -1;
}

int numberofoccurrences(int *arr, int low, int high, int number){
	int one= first(arr, low, high, number);
	int two = second(arr, low, high, number);
	return two-one+1;
}

int main(){
	int arr[] = {1, 2, 2, 3, 3, 3, 3};
	size = sizeof(arr)/sizeof(arr[0]);
	cout<<numberofoccurrences(arr, 0, size-1, 3);
}