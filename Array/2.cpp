/*Majority Element*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool ismajorityelement(int *arr, int size){
	int T[1000];
	for(int i = 0; i < size; ++i)
		++T[arr[i]];
	for (int i = 0; i < 1000; ++i)
		T[i] = 0;

	for(int i = 0; i < size; ++i){
		if(T[arr[i]] > (size+1)/2)
			return true;	
	}
	return false;
}

int main(){
	int arr[] = {1, 3, 3, 1, 2, 2};
	int size = sizeof(arr)/sizeof(int);
	if(ismajorityelement(arr, size))
		cout<<"Yes\n";
	else
		cout<<"No\n";
}