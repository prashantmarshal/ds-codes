/*maximum product subarray*/

#include <bits/stdc++.h>
using namespace std;

void solve(int *arr, int size)
{
	int maxendinghere = max(0,arr[0]), maxone = max(0,arr[0]), minone = min(0,arr[0]);

	for(int i=1; i<size; ++i){
		int temp = maxone;
		maxone = max(max(arr[i]*minone, arr[i]*maxone), arr[i]);
		minone = min(min(arr[i]*minone, arr[i]*temp), arr[i]);
		maxendinghere = max(maxone, maxendinghere);

	}
	cout<<maxendinghere<<endl;
}

int main(){
	int arr[] = {-1, -3, -10, 0, 60};
	int size = sizeof(arr)/sizeof(arr[0]);
	solve(arr, size);
}