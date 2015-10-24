#include <bits/stdc++.h>
using namespace std;

#define forr(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define pi(i) printf("%d", i)
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])

int solve(int arr[], int low, int high, int k, int size){
	cout<<low<<" "<<high<<endl;
	if(low > high)
		return low;

	if(low == high && arr[low] <= k){
		while(low < size && arr[low++] == k);
		if(arr[low-1] == k)
			return -1;
		else
			return low-1;
	}

	int mid = (low+high)/2;
	if(arr[mid] > k){
		if(arr[mid-1]<k)
			return mid;
		return solve(arr, low, mid-1, k, size);
	}
	else if(arr[mid] < k){
		if(arr[mid+1]>k)
			return mid;
		return solve(arr, mid+1, high, k, size);
	}
	else if(arr[mid] == k){
		while(mid <size && arr[mid++] == k);
		if(arr[mid-1] == k)
			return -1;
		else
			return mid-1;
	}
}


int main(int argc, char const *argv[])
{
	int arr[] = {2,2,3,3,5,5,6,6,7,7,8,8,9,9};
	int size = size(arr);
	int k;
	cin>>k;
	cout<<arr[solve(arr, 0, size-1, k, size)];
	return 0;
}