#include <iostream>
#include <stack>
using namespace std;

void prevsmaller(int *arr, int size){
	stack <int> mystack;
	for(int i = 0; i < size; ++i){
		int temp = arr[i];
		while(!mystack.empty() && mystack.top() >= arr[i])
			mystack.pop();
		if(!mystack.empty())
			arr[i] = mystack.top();
		else
			arr[i] = -1;
		mystack.push(temp);
	}
}

int main(){
	int arr[] = {1, 3, 0, 2, 5};
	int size = sizeof(arr)/sizeof(arr[0]);
	prevsmaller(arr, size);
	for (int i = 0; i < size; ++i)
		cout<<arr[i]<<" ";
	return 0;
}