#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void permute(char arr[], int l, int len){
	
	for(int i = 0; i < l; i++){
		cout<<arr[i];
	}
	cout<<endl;

	if(l == len+1)
		return;
	
	for(int i = l; i < len; ++i){
		swap(arr[i], arr[l]);
		permute(arr, l+1, len);
		swap(arr[i], arr[l]);
	}
}

int main(){
	char arr[100];
	gets(arr);
	int n = strlen(arr);
	permute(arr, 0, n);
}
