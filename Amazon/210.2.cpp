#include <iostream>
using namespace std;


void shift(int *arr, int start, int upto, int temp){
	for(int i = start; i <= upto; ++i){
		int temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
	}
}

void printalternativeposneg(int *arr, int size){
	int p = 0, q = 1;
	for(int i = 0; i < size; ++i){

		if(i&2 == 0 && arr[i] < 0){
			p = i;
			while(arr[p] < 0)
				++p;
			if(p >= size)
				break;
			swap(arr[i], arr[p]);
			shift(arr, i+1, p, arr[p]);
		}else if(i%2 == 1 && arr[i] >= 0){
			q = i;
			while(arr[q] >= 0)
				++q;
			if(q >= size)
				break;

			swap(arr[i], arr[q]);
			shift(arr, i+1, q, arr[q]);
		}
	}
}


int main(){
	int arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0; i < size; ++i)
		cout<<arr[i]<<" " ;
	cout<<endl;
	printalternativeposneg(arr, size);
	for(int i = 0; i < size; ++i)
		cout<<arr[i]<<" " ;
	
}