#include <bits/stdc++.h>
using namespace std;


void solve(int *arr, int size){
	
	std::vector<int> vp;
	std::vector<int> vn;

	int p2=0,n2=0;
	for (int i = 0; i < size; ++i)
		if(arr[i] < 0){
			n2++;
			vn.push_back(arr[i]);
		}
		else{
			p2++;
			vp.push_back(arr[i]);
		}

	int p=0,n=0,i=0;
	bool even = true;

	while(p < p2 && n < n2){
		if(even){
			arr[i++] = vn[n++];
			even = !even;
		}else{
			arr[i++] = vp[p++];
			even = !even;
		}
	}
	
	while(n<p2)
		arr[i++]=vn[n++];
	
	while(p<p2)
		arr[i++]=vp[p++];
	
	for (int i = 0; i < size; ++i)
		cout<<arr[i]<<" ";

}

int main(int argc, char const *argv[])
{
	int arr[] =  { -3, 1, 5 , 7, -4, -7, -6} ;
	int size = sizeof(arr)/sizeof(arr[0]);
	solve(arr,size);
	return 0;
}