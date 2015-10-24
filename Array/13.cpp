/*Segregate 0s and 1s in an array*/

#include <iostream>
using namespace std;

int count = 0;
void segregate(int *arr, int size){ // not in minimum number of swaps
	int one_pos;
	int i = 0;
	while(i < size){
		if(arr[i] == 1){
			one_pos = i;
			break;
		}
		++i;
	}
	++i;
	while(i < size){
		if(arr[i] == 0){
			swap(arr[i], arr[one_pos]);
			++count;
			++one_pos;
		}
		++i;
	}

	for (int i = 0; i < size; ++i)
		cout<<arr[i]<<" ";
	cout<<"\n"<<count<<endl;
}

void segregateminimumswaps(int *arr, int size){ // minimum swaps
	int zero_pos;
	int j = size-1;
	while(j > 0){
		if(arr[j] == 0){
			zero_pos = j;
			break;
		}
		--j;
	}
	int i = 0;
	while(i < size && zero_pos > i){
		if(arr[i]==0)
			continue;
		if(arr[i] == 1){
			swap(arr[i], arr[zero_pos]);
			++count;
			--zero_pos;
		}
		++i;
		while(arr[i] == 0)
			++i;
		while(arr[zero_pos] == 1){
			--zero_pos;
		}
	}
	// for (int i = 0; i < size; ++i)
	// 	cout<<arr[i]<<" ";
	cout<<"\n"<<count<<endl;


}
int count2 = 0;
void segregateminimumswaps2(int *arr, int size){
	int i=0, j=size-1;
	while(i < j){
		while(arr[i]==0)
			++i;
		while(arr[j] == 1)
			--j;
		if(i < j){
			swap(arr[i],arr[j]);
			count2++;
			++i;
			--j;
		}
		while(arr[i]==0 && i < j)
			++i;
		while(arr[j] == 1 && j > i)
			--j;
	}
	cout<<count2<<endl;
}

int main(){
	int arr[] = {1,0,1,0,1,0,0,0,0,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,0,1,0};
	int arr2[] = {1,0,1,0,1,0,0,0,0,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,0,1,0};
	int size = sizeof(arr)/sizeof(int);
	segregateminimumswaps(arr, size);
	cout<<endl;
	segregateminimumswaps2(arr2, size);

}