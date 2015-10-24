/*minimum numbers to be deleted so that twice min max*/
#include <iostream>
using namespace std;


int findceil(int arr[], int low, int high, int c){
	int prev = low;
	for(int i = low+1; i <= high; ++i){
		if(arr[i] >= c)
			return prev;
		else
			prev = i;
	}
}

int solve(int arr[], int t){
	int j, del = t;
	for(int i = 0; i < t; ++i){
		j = findceil(arr, i, t-1, 2*arr[i]+1);
		del = min(del,t-j+i);
	}
	return del;
}

int main(){
	int t;
	cin>>t;
	int arr[t];
	for(int i = 0; i < t; ++i)
		cin>>arr[i];
	cout<<solve(arr,t);
}
