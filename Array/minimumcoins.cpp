/*important*/
#include <iostream>
#include <limits.h>
using namespace std;

int countminimum(int *arr, int coins, int sum){
	if(sum == 0)
		return 0;
	
	int res = INT_MAX;
	for(int i = 0; i < coins; ++i){
		if(arr[i] <= sum){
			int mincoins = min(mincoins, countminimum(arr, coins, sum-arr[i]));
			if(mincoins != INT_MAX)
				res = min(res, 1+mincoins);
		}
	}
	return res;
}

int countminimum2(int *arr, int coins, int sum){
	if(sum == 0)
		return 0;
	if(coins == 0)
		return 10000;
	if(arr[coins-1] > sum)
		return 10000;
	return min(1+countminimum2(arr,coins-1,sum-arr[coins-1]), countminimum2(arr,coins-1,sum));
}

int countminimumdp(int *arr, int coins, int sum){

	int table[sum+1];

	table[0] = 0; // for sum = 0

	for(int i = 1; i <= sum; ++i)
		table[i] = INT_MAX;

	for(int i = 1; i <= sum; ++i){
		int res = INT_MAX;

		for(int k = 0; k < coins; ++k){ // if taken kth coin already, how many were required for sum to be sum - arr[k] and take min of it
			if(i >= arr[k] && table[i-arr[k]] != INT_MAX){
				res = min(res, table[i-arr[k]]);
			}
		}
		table[i] = 1+res;
	}

	return table[sum];


}

int main(){

	int arr[] = {9, 6, 5, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<countminimum(arr, size, 11)<<endl<<countminimum2(arr, size, 11);

}