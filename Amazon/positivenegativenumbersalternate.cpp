/*positive negative numbers alternate*/

#include <bits/stdc++.h>
using namespace std;


void shift(int arr[], int start, int last){
	int temp;
	for(int k = start; k < last; ++k){
		temp = arr[k+1];
		arr[k+1]=arr[k];
	}
	arr[start] = temp;
}

int main(){
	int arr[] = { 9, 4, -2, -1, 5, 0, -5, -3, -2, -5, -6, -9};
	int size = sizeof(arr)/sizeof(arr[0]);
	int j;
	for(int i = 0; i < size; ++i){
		if(i%2 == 0 && arr[i] < 0){
			j = i;
			while(arr[i]<0 && i < size) ++i;
			if(i<size)
				shift(arr, j, i);
			else 
				break;
			i=j;
		}else if(i%2 != 0 && arr[i] >= 0){
			j = i;
			while(arr[i]>=0 && i < size) ++i;
			if(i<size)
				shift(arr, j, i);
			else 
				break;
			i=j;
		}
	}

	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
}