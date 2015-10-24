#include <iostream>
using namespace std;

int findLargestSumPair(int *arr, int n){
	if(n <= 1)
		return (n == 0)?0:n;

	int maxi = max(arr[0], arr[1]); int mini = min(arr[0], arr[1]);
	for(int i = 2; i < n; ++i){
		if(arr[i] > mini){
			mini = arr[i];
			int temp = maxi;
			maxi = max(mini, maxi);
			mini = min(temp, mini);
		}
	}

	return mini+maxi;
}

int main(){
    int arr[] = {12, 34, 10, 6, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max Pair Sum is " << findLargestSumPair(arr, n);
    return 0;
}