/*second largest in array*/
#include <iostream>
using namespace std;

int main(){
	int arr[] = {3,5,6,4,2,16,11,8,12,9,14};
	int a,b;
	int n = sizeof(arr)/sizeof(arr[0]);
	a = max(arr[0],arr[1]);
	b = min(arr[0],arr[1]);
	for(int i = 2; i < n; ++i){
		if(arr[i] > max(a,b)){
			a = b;
			b = arr[i];
		}else if(arr[i] > min(a,b)){
			a = arr[i];
		}
	}

	cout<<a<<endl;
}