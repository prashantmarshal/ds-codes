/*largest sum contiguous array*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)
#define scanint(n) scanf("%d", &n)
#define printint(n) printf("%d", n);


int maxsumsubarray(int *arr, int size, int K){ // dynamic programming
	int maxsum = arr[0];
	int max_so_far = maxsum;

	for (int i = 1; i < size; ++i){
		maxsum = max((maxsum+arr[i])%K, arr[i]%K); // either the window from previous plus current element or just ththe current element
		max_so_far = max(maxsum%K, max_so_far%K);
	}

	return max_so_far;

}


int main(){
	int t;
	scanint(t);
	while(t--){
		int k;
		scanint(k);
		int K;
		scanint(K);
		int *arr = new int[k];
		For(i,0,k)
		scanint(arr[i]);
		cout<<maxsumsubarray(arr, k, K);

	}
}