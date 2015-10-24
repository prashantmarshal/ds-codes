/*Find common elements in three sorted arrays*/

#include <iostream>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;


void printintersectionofthreearrays(int *arr1, int *arr2, int *arr3, int size1, int size2, int size3){
	int  i=0, j=0, k=0;
	while(i < size1 && j < size2 && k < size3){
		if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
			cout<<arr1[i]<<" "; ++i; ++j; ++k;
		}
		else if(arr1[i] < arr2[j])
			++i;
		else if(arr2[j] < arr3[k])
			++j;
		else
			k++;		
	}
}

int main(){
	int arr1[] = {1, 5, 10, 20, 40, 80};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int size3 = sizeof(arr3)/sizeof(arr3[0]);

    printintersectionofthreearrays(arr1, arr2, arr3, size1, size2, size3);

}