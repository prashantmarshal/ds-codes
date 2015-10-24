/*median of two sorted arrays equal size*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>
using namespace std;


int median(int arr[], int n){
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}

int getMedian(int *arr1, int*arr2, int size){

	if(size == 1)
		return (arr1[0]+arr2[0])/2;
	if(size == 2)
		return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]))/2;
	
	int m1 = median(arr1, size);
	int m2 = median(arr2, size);


    

	if(m1 == m2)
		return m1;
	if(m1 < m2){
		getMedian(arr1+ (size-1)/2, arr2, (size%2)?(size+2)/2:(size/2));
	}else
		getMedian(arr2+ (size-1)/2, arr1, (size%2)?(size+2)/2:(size/2));

}

int main(){
	int ar1[] = { 10, 11, 12, 15, 20 };
    int ar2[] = { 10, 11, 12, 15, 20 };
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
    	printf("Median is %d", getMedian(ar1, ar2, n1));
}