#include <iostream>
using namespace std;

void search(int arr[], int low, int high){
	if(low > high)
		return;
	if(low == high){
		cout<<arr[low]<<endl;
		return;
	}

	int mid = (low+high+1)/2;
	if(mid%2 == 0){
		if(arr[mid+1] == arr[mid]) // odd element yet to come
			search(arr, mid+2, high);
		else
			search(arr, low, mid-1);
		
	}else{
		if(arr[mid] == arr[mid-1]) // odd element on left
			search(arr, mid+1, high);
		else
			search(arr, low, mid-1);
	}
	
}

int main(){
	int arr[] = {1, 1, 2, 2, 1, 1, 2, 2, 13, 1, 1, 40, 40};
	int len = sizeof(arr)/sizeof(arr[0]);
	search(arr, 0, len-1);
	return 0;
}