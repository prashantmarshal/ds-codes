#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


long long int findmaxstoredwater(long long int *arr, long long int n){
	long long int left[n], right[n];

	left[0] = arr[0];
	for(long long int i = 1; i < n; ++i)
		left[i] = max(left[i-1], arr[i]);
	
	right[n-1] = arr[n-1];
	for(long long int i = n-2; i >= 0; --i)
		right[i] = max(right[i+1], arr[i]);
	
	long long int water = 0;
	for(long long int i = 0; i < n; ++i)
		water += min(left[i], right[i]) - arr[i];
	return water;
}

int main(int argc, char const *argv[]){
	long long int T;
	cin>>T;
	while(T--){
		long long int n;
		scanf("%lld", &n);
		long long int *arr = new long long int[2*n-1];
		for(long long int i = 0; i < 2*n-1; ++i){
			scanf("%lld", &arr[i]);
			if(i != 2*n-2)
				arr[++i] = 0;
		}
		cout<<findmaxstoredwater(arr, n+n-1)<<endl;
	}
	return 0;
}