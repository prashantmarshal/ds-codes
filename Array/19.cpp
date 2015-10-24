/*Find subarray with given sum numbers can only be non-negative*/

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int subarraysum(int *arr, int size, int sum){
	int curr_sum = arr[0];
	if(curr_sum == sum)
		return 1;
	int j = 0;
	for(int i = 1; i < size; ++i){
		if(curr_sum+arr[i] > sum)
			curr_sum = curr_sum - arr[j++] + arr[i];
		else if(curr_sum+arr[i] < sum)
			curr_sum += arr[i];
		else
			return 1;
	}

	return 0;
}

int main(){
	int arr[] = {15, 9, 4, 8, 9, 5, 10, 23};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 23;
    if(subarraysum(arr, size, sum))
	    cout<<"Yes\n";
    else
    	cout<<"No\n";
}