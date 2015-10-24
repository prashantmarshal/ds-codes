/*Maximum profit by buying and selling a share at most twice*/

#include <bits/stdc++.h>
using namespace std;

void solve(int *arr, int size)
{
	int profit[size];
	memset(profit,0, sizeof profit);

	int min = arr[0];
	profit[0] = 0;
	for (int i = 1; i < size; ++i){
		profit[i] = max(profit[i-1], arr[i]-min);
		if(min>arr[i])
			min = arr[i];
	}

	int profit2[size];
	memset(profit2,0, sizeof profit2);
	profit2[size-1] = 0;
	int max_ = arr[size-1];
	for (int i = size-2; i >= 0; --i){
		profit2[i] = max(profit2[i+1], max_-arr[i]);
		if(arr[i] > max_)
			max_ = arr[i];
	}

	int res = 0;
	for(int i = 0; i < size; ++i){
		if(profit2[i]+profit[i] > res)
			res = profit2[i]+profit[i];
	}
	cout<<res<<endl;

}

int main(int argc, char const *argv[])
{
	int arr[] = {10, 22, 5, 75, 65, 80};
	int size = sizeof(arr)/sizeof(arr[0]);
	solve(arr, size);
	return 0;
}