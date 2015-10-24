#include <iostream>
#include <stdio.h>
using namespace std;

/*long long int maxprofit(long long int *arr, long long int size, long long int n){
	if(n < 1)
		return 0;
	return max(maxprofit(arr, size+1, n-1) - arr[n-1], max(maxprofit(arr, size, n-1), size*arr[n-1] + maxprofit(arr, 0, n-1)));
}
*/

void maxstock(long long int *arr, long long int n){
	long long int sum = 0;
	long long int stocks = 0, curr_max = 0;
	for(long long int i = n-1; i >= 0; --i){
		if(arr[i] > curr_max){
			sum += stocks*curr_max;
			curr_max = arr[i];
			stocks = 0;
		}else {
			++stocks;
			sum = sum - arr[i];
		}
		if(i == 0 && arr[i] < curr_max)
			sum += stocks*curr_max;
		
	}

	printf("%lld\n", sum);

}

int main(){
	long long int T;
	cin>>T;

	while(T--){
		long long int n; cin>>n;
		long long int arr[n];
		for (long long int i = 0; i < n; ++i)
			scanf("%lld", &arr[i]);
		maxstock(arr, n);
	}
}

// http://www.geeksforgeeks.org/add-two-bit-strings/
// http://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
// http://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/