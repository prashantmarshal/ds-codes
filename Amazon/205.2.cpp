#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {1,5,2,4,8,9,6,3,5,7,8,9,6,3,1,2,5,4,7,8,9,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+size);
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int i = 0, j = size-1;
	int count=0;
	while(i < j && 2*arr[i] < arr[j]){
		int diff1,diff2;
		diff1 = arr[j-1]-arr[i];
		diff2 = arr[j]-arr[i+1];
		if(diff1>diff2)
			--j;
		else
			++i;
		++count;
		if(i == j){
			cout<<"cant";
			return 0;
		}
	}
	cout<<arr[i]<<" " <<arr[j]<< " " <<i<< " " <<j<<endl;
	cout<<count<<endl;
}