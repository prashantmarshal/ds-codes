#include <bits/stdc++.h>
using namespace std;


int solve(int arr[], int size){
	int sum=0;
	for(int i=0; i<size; ++i){
		if(arr[i]>sum+1)
			return sum+1;
		else{
			sum = sum+arr[i];
		}
	}
	return sum+1;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 22, 112, 445, 666, 999, 8888, 9999, 10000, 231615};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<solve(arr,size);
	return 0;
}