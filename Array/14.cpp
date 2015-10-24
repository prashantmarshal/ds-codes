/*find duplicates in O(n) time*/

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;


void printduplicates(int *arr, int size){
	for(int i = 0; i < size; ++i){
		int element = abs(arr[i]);
		if(arr[element] > 0)
			arr[element] = -arr[element];
		else if(arr[element] < 0){
			cout<<abs(arr[i])<<" ";
			arr[element] = -arr[element];
		}
	}
	cout<<endl;
}

int main(){

	int arr[] = {1,2,3,1,3,6,6};
	int size = sizeof(arr)/sizeof(int);
	printduplicates(arr, size);

}