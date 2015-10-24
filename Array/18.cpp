/*Dynamic Programming | Set 18 (Partition problem)
Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.
*/


#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>
using namespace std;

bool checksubsetsum(int *arr, int n, int sum){
	if(sum < 0)
		return false;
	if(sum == 0)
		return true;
	if(n < 0)
		return false;

	return checksubsetsum(arr, n-1, sum) || checksubsetsum(arr, n-1, sum - arr[n]);
}

int findpartition(int *arr, int size, int sum);

bool issubsetsum(int *arr, int size){
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += arr[i];
	
	if(sum%2 == 0){
		sum /= 2;
		return findpartition(arr, size, sum);
	}
		// return checksubsetsum(arr, size-1, sum);
		
	else
		return false;
}

int findpartition(int *arr, int size, int sum){
	int partition[sum+1][size];

	for (int i = 0; i < size; ++i)
		for (int j = 0; j <= sum; ++j)
			partition[i][j] = 0;

	
		
		cout<<partition[0][7];
		partition[1][0] = 1;
		cout<<partition[0][7];
		return 0;
	
	// for (int i = 0; i < size; ++i){

	// }

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j <= sum; ++j)
		{
			cout<<partition[i][j]<<" ";
			// if(partition[i][j])
			// 	cout<<"1"<< " ";
			// else
			// 	cout<<"0"<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i = 1; i <= sum; ++i){

		partition[0][i] = false;
	}

	
return 0;

	/*for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j <= sum; ++j)
		{
			if(partition[i][j])
				cout<<"1"<< " ";
			else
				cout<<"0"<<" ";
		}
		cout<<endl;
	}

	cout<<endl;
	return 0;

	for(int i = 0; i <= sum; ++i)
		partition[0][i] = false;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j <= sum; ++j)
		{
			if(partition[i][j])
				cout<<"1"<< " ";
			else
				cout<<"0"<<" ";
		}
		cout<<endl;
	}

	for (int i = 0; i < size; ++i)
		for (int j = 0; j <= sum; ++j)
			partition[i][j] = false;
		
	for(int i = 1; i < size; ++i){
		for (int j = 1; j <= sum; ++j){
			if(j-arr[i] >= 0)
				partition[i][j] = partition[i-1][j] || partition[i-1][j - arr[i]];
		}
	}

	

	return partition[sum][size];*/

}

int main(){

	int arr[] = {7,2,3,1,3,6,6};
	int size = sizeof(arr)/sizeof(int);
	if(issubsetsum(arr, size))
		cout<<"Yes\n";
	else
		cout<<"No\n";
}