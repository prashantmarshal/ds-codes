/*union and intersection of two sorted arrays*/

#include <iostream>
using namespace std;

void printunion(int *arr1, int *arr2, int size1, int size2){
	int i = 0, j = 0;
	while(i < size1 && j < size2){
		if(arr1[i] < arr2[j]){
			cout<<arr1[i]<<" ";
			i++;
		}else if(arr1[i] > arr2[j]){
			cout<<arr2[j]<<" ";
			j++;
		}else if(arr1[i] == arr2[j]){
			cout<<arr2[j]<<" ";
			j++;i++;
		}
	}
	while(i < size1){
		cout<<arr1[i]<<" ";
		i++;
	}
	while(j < size2){
		cout<<arr2[j]<<" ";
		j++;
	}

}

int main(){
	int arr1[] = {1, 3, 4, 5, 7};
	int arr2[] = {2, 3, 5, 6};
	printunion(arr1, arr2, sizeof(arr1)/sizeof(int), sizeof(arr2)/sizeof(int));
}