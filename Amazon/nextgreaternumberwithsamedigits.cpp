#include <bits/stdc++.h>
using namespace std;

void solve(char arr[]){
	int len=strlen(arr);

	int mingw = len-1;
	int i = len-1;

	while(i>= 0 && arr[i-1] > arr[i]){ 
		if(arr[mingw] < arr[i])
			mingw = i;
		i--;
	}

	if(i==0){
		printf("cant\n");
		return;
	}
	i--;

	for(int j = i+1; j< len; ++j){
		if(arr[j] > arr[i] && arr[j] < arr[mingw])
			mingw = j;
	}
	swap(arr[i], arr[mingw]);

	sort(arr+i+1, arr+len);

	for (int i = 0; i < len; ++i)
		cout<<arr[i];
}
int main(){
	char arr[] = "1987654321";
	solve(arr);
}