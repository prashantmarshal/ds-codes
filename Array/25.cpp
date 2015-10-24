/*smallest number not represnted by any elements in array*/

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;



int findSmallest(int *arr, int size){
	int res = 0;
	for(int i = 0; i < size; ++i){
		if(arr[i] > res+1)
			return res+1;
		else if(arr[i] <= res+1){
			res += arr[i];
		}
	}
	return res+1;
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 22, 112, 445, 666, 999, 8888, 9999, 10000, 231615};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<findSmallest(arr, size)<<endl;

}