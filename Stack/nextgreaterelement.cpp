#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	int arr[10] = {5,4,3,2,8,6,15,11,14,9};
	stack <int> mystack;
	int size = sizeof(arr)/sizeof(int);
	int i = 0;
	int arr2[10] = {5,4,3,2,8,6,15,11,14,9};
	while(i < size){
		if(mystack.size() == 0){
			mystack.push(arr[i]);
		}else{
			if(mystack.top() < arr[i]){
				int j = i-1;
				while(mystack.size() && mystack.top() < arr[i]){
					arr[j--] = arr[i];
					mystack.pop();
				}
				mystack.push(arr[i]);
			}else
				mystack.push(arr[i]);
		}
		++i;
	}

	for (int i = 0; i < size; ++i)
		if(arr2[i] == arr[i])
			arr[i] = -1;
		
	for (int i = 0; i < size; ++i)
		cout<<arr[i]<<" ";


}