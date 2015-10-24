/*minimum distance between two numbers*/

#include <iostream>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;


int minimumdistance(int *arr, int size, int a, int b){
	int mindistance = INT_MAX;
	int prev;
	for(int i = 0; i < size; ++i){
		if(arr[i] == a || arr[i] == b){
			prev = i;
			break;
		}
	}
	for(int i = prev+1; i < size; ++i){
		if((arr[i] == a || arr[i] == b) && arr[i] != arr[prev]){
			mindistance = i - prev;
			prev = i;
			break;
		}

	}
	cout<<prev<<endl;

	for (int i = prev+1; i < size; ++i){
		if((arr[i] == a || arr[i] == b) && arr[i] != arr[prev]){
			if(mindistance > i - prev)
				mindistance = i - prev;
			prev = i;
		}
	}
	return mindistance;
}

int main(){
	int arr[] = {2, 5, 3, 5, 4, 4, 2, 3};
	int size = sizeof(arr)/sizeof(int);
	int a = 3, b = 2;
	cout<<minimumdistance(arr, size, a, b);
}