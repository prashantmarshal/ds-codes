#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)

void printzigzag(int *arr, int l){

	bool flag = true;
	For(i,0,l-1){
		if(flag && arr[i] < arr[i+1]) swap(arr[i], arr[i+1]);
		else if(!flag && arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);		
		flag = !flag;
	}

	For(i,0,l) cout<<arr[i]<<" ";

}

int main(){
	int arr[] = {3,7,4,5,2,9,12,6};
	int l = sizeof(arr)/sizeof(arr[0]);
	printzigzag(arr, l);
}