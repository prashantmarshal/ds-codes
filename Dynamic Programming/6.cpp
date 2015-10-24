/*Dynamic Programming | Set 7 (Coin Change)*/

#include <iostream>
#include <string.h>
using namespace std;


int count(int *arr, int n, int sum){

	if(sum == 0) // if sum is 0 how many coins for this subproblem --> 0
		return 1;
	if(sum < 0)
		return 0;
	if(n <= 0) // if n the number of coins is 0, what sum it can generate => 0, hence number of ways --> 0
		return 0;
	return count(arr, n-1, sum) + count(arr, n, sum - arr[n-1]);

}

int countdp(int *arr, int coins, int sum){
	int table[coins+1][sum+1]; // coins vs sum

	for(int i = 0; i <= coins; ++i){
		for(int k = 0; k <= sum; ++k){
			
			if(i == 0 && k == 0)
				table[i][k] = 1;
			
			else if(i == 0) // if coins are 0
				table[i][k] = 0;
			
			else if(k == 0) // if sum is 0
				table[i][k] = 1;

			else{
				if((k - arr[i-1]) >= 0)
					table[i][k] = table[i][k-arr[i-1]] + table[i-1][k];
				
				else
					table[i][k] = table[i-1][k];
			}
		}
	}
	return table[coins][sum];
}

int main(){
    int arr[] = {1, 2, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<count(arr, size, 4);cout<<endl;
    cout<<countdp(arr, size, 4);
}