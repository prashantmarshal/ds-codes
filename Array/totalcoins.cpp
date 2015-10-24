#include <iostream>
using namespace std;


int count(int *arr, int m, int sum){
	if(sum == 0)
		return 1;
	if(m < 0 && sum > 0 || sum < 0)
		return 0;
	return count(arr, m, sum - arr[m]) + count(arr, m-1, sum);
}

int countdp(int *arr, int m, int sum){
	int table[m+1][sum+1];
	for(int i = 0; i <= m; ++i){
		for(int k = 0; k <= sum; ++k){
			table[i][k] = 0;
			if(k == 0)
				table[i][k] = 1;
			else if(k != 0 && i == 0)
				table[i][k] = 0;
			else{
				if(k-arr[i-1] >= 0) // as coins selecting from arr should be i-1
					table[i][k] = table[i][k-arr[i-1]] + table[i-1][k];
				else
					table[i][k] = table[i-1][k];
			}
		}
	}

	return table[m][sum];
}

int main(){
	int arr[] = {1,2,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<countdp(arr, size-1, 4);
}