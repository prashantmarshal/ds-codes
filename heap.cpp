#include <iostream>
using namespace std;


class heap{
public:
	int arr[100];
	int count;
	heap(){
		count = 0;
	}

	void insert(int a){
		arr[count] = a;
		int i = count;
		count++;

		while(i >= 0 && arr[i/2] > arr[i]){
			int temp = arr[i/2];
			arr[i/2] = arr[i];
			arr[i] = temp;
			i = i/2;
		}
	}

	int extractmin(){
		int val = arr[0];
		arr[0] = arr[count-1];
		count=count-1;

		int i = 0;
		while(i < count){
			if(arr[2*i+1] < arr[i]){
				int temp = arr[2*i+1];
				arr[2*i+1] = arr[i];
				arr[i] = temp;
			}else if(arr[2*i+2] < arr[i]){
				int temp = arr[2*i+2];
				arr[2*i+2] = arr[i];
				arr[i] = temp;
			}else
			break;
		}

		return val;

	}

};
int main(){
	heap h;
	h.insert(6);
	h.insert(5);
	
	h.insert(2);
	h.insert(1);
h.insert(4);
	h.insert(3);	cout<<h.extractmin();
		cout<<h.extractmin();
			cout<<h.extractmin();
}