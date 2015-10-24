#include <bits/stdc++.h>
using namespace std;

int binarysearch(int *arr, int low, int high, int number){
	if(low > high)
		return -1;
	if(low == high && arr[low] != number)
		return -1;

	int mid = (low+high)/2;

	if((arr[mid] == number && mid == 0) || (arr[mid] == number && arr[mid-1] != number)){
		return mid;
	}else if(arr[mid] >= number)
		return binarysearch(arr, low, mid-1,number);
	else
		return binarysearch(arr, mid+1, high,number);

	return -1;

}


void solve(int *arr, int size, int number){
	int mid= binarysearch(arr, 0, size-1, number);
	if(mid==-1)
		cout<<size-1;
	else
		cout<<mid-1;
}

int main(int argc, char const *argv[])
{
	int arr[] = {5,5,8,8,9,11,11,13};
	int number;// = 8;
	cin>>number;
	int size=sizeof(arr)/sizeof(arr[0]);
	solve(arr, size, number);
	return 0;
}