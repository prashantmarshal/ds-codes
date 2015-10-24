/*Rearrange positive and negative numbers in O(n) time and O(1) extra space*/

#include <bits/stdc++.h>
using namespace std;
#define size(arr) sizeof(arr)/sizeof(arr[0])

void solve(int arr[], int size){
	int pivot = 0;
	int i=0,j=size-1;

	while(i<j){
		while(arr[i]>0)
			++i;
		while(arr[j]<0)
			--j;
		if(i<j){
			swap(arr[i],arr[j]);
			++i,--j;
		}
	}
	j++;i=0;
	int p=1;
	while(j<size && arr[p]>=0 && arr[j]<0){
		swap(arr[p],arr[j]);
		p=p+2;
		++j;
	}

	for (int i = 0; i < size; ++i)
		cout<<arr[i]<<" ";

}

int main(int argc, char const *argv[])
{
	int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
	int size = size(arr);
	solve(arr, size);	
	return 0;
}