/*Find the minimum distance between two numbers*/

#include <bits/stdc++.h>
using namespace std;


void solve(int arr[], int size){
	int a = 3, b = 6,i =0;

	while(i < size && arr[i] != a && arr[i] != b){
		++i;
	}
	int mindist = 1000;

	int prev = i;
	++i;
	while(i < size){
		if((arr[i] == a || arr[i] == b) && arr[i] != arr[prev]){
			if(i - prev < mindist)
				mindist = i - prev;

		}
		if(arr[i] == arr[prev])
			prev = i;
		++i;
	}

	cout<<mindist<<endl;

}

int main(int argc, char const *argv[])
{
	int arr[] = {3,5,4,6,5,8,9,3,7,8,5,6,9,5,2,3,9,6,8,7,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	solve(arr, size);
	return 0;
}