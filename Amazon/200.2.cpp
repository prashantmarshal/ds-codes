/*important*/

#include <iostream>
using namespace std;

int main(){
	int arr[] = {3,3,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	int t[size];

	for(int i = 0; i < size; ++i){
		if(i == 0){
			if(arr[i] < arr[i+1])
				t[i] = 1;
			else
				t[i] = 2;
		}
		else if(i == size-1){
			if(arr[i] < arr[i-1])
				t[i] = 1;
			else
				t[i] = 2;
		}
		else{
			if(arr[i] > max(arr[i-1],arr[i+1]))
				t[i] = 3;
			else if(arr[i] >= min(arr[i-1], arr[i+1]))
				t[i] = 2;
			else
				t[i] = 1;
		}
	}

	
	for (int i = 1; i < size-1; ++i)
		if(t[i] <= t[i-1] && arr[i] > arr[i-1])
			t[i] = t[i-1]+1;
		else if(t[i] <= t[i-1] && arr[i] == arr[i-1])
			t[i] = t[i-1];

	for (int i = size-2; i >= 1; --i)
		if(t[i] <= t[i+1] && arr[i] > arr[i+1])
			t[i] = t[i+1]+1;
		else if(t[i] <= t[i+1] && arr[i] == arr[i+1])
			t[i] = t[i+1];


	
	if(t[0] == 2)
		t[0] = 1+t[1];

	if(t[size-1] == 2)
		t[size-1] = 1+t[size-2];

	for (int i = 0; i < size; ++i)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;

	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += t[i];
	cout<<sum<<endl;
}