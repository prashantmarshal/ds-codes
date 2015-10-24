/*kth largest in an array*/

#include <iostream>
#include <queue>
using namespace std;

void klargest(int *arr, int k, int size){ // bubble sort for k times order nk

	for(int i = 0; i < k; ++i){
		for(int j = i+1; j < size; ++j){
			if(arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
	for (int i = 0; i < k; ++i)
		cout<<arr[i]<<" ";
}

void klargest2(int *arr, int k, int size){ // priority queue
	priority_queue <int> pq;
	for(int i = 0; i < k; ++i)
		pq.push(arr[i]);
	int pqsize = pq.size();


	for(int i = k; i < size; ++i){
		if(pq.top() > arr[i]){
			pq.pop();
			pq.push(arr[i]);
		}
	}

	for (int i = 0; i < pqsize; ++i){
		cout<<pq.top()<<" ";
		pq.pop();
	}
}


int main(){
	int arr[] = {2,6,4,7,8,9,5,1};
	int size = sizeof(arr)/sizeof(int);
	klargest2(arr, 3, size);
	return 0;
}