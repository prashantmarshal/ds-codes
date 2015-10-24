/*number of triangles*/

#include <bits/stdc++.h>
using namespace std;


void solve(int *arr, int size){
	sort(arr, arr+size);
	int cnt= 0;
	for (int i = 0; i < size-2; ++i){
		for(int j = i+1; j < size; ++j){
			int k = j+1;
			while(k < size && arr[k++] < arr[i]+arr[j]){
				cnt++;
			}
		}

	}
	cout<<cnt<<endl;

}

int main(int argc, char const *argv[])
{
	int arr[] = {10, 21, 22, 100, 101, 200, 300};
	int size = sizeof(arr)/sizeof(arr[0]);
	solve(arr, size);
	return 0;
}