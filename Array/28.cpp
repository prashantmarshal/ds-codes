/*Given an array of Numbers and an integer K. Find the total number of Distinct Elements in the contiguous sub-arrays of size K each.*/

#include <iostream>
#include <map>
using namespace std;

int givedistinct(int *arr, int start, int last, int size){
	if(last > size-1)
		last = size-1;
	map<int, int> mymap;
	for(int i = start; i <= last; ++i)
		++mymap[arr[i]];

	return mymap.size();
	
}

int totaldistinct(int *arr, int size){
	int start = 0;
	int last = 4;
	do{
		cout<<givedistinct(arr, start, last, size)<<" ";
		start = last+1;
		last += 5;
	}while(start < size);
}

int main(){
	int arr[] = {1,2,5,1,21,	21,11,51,51,21, 12,12,121,12,2,	31,31,212,121,121,	22,121,212,12};
	int size = sizeof(arr)/sizeof(int);
	totaldistinct(arr, size);
}
