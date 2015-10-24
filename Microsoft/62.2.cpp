#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define pi(i) printf("%d", i)
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])

void solve(int *arr, int size, int k){
	map<int, int> count;
	int distinct=0;
	For(i,0,k){
		count[arr[i]]++;
		if(count[arr[i]] == 1)
			distinct++;
	}
	cout<<distinct<<" ";
	int first = 0;
	For(i,4,size)
		{
			count[arr[first]]--;
			if(count[arr[first]] == 0)
				distinct--;
			count[arr[i]]++;
			if(count[arr[i]]==1)
				distinct++;

			cout<<distinct<<" ";
			++first;
		}
}

int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 1, 3, 4, 2, 3};
	int size = size(arr);
	int k = 4;
	solve(arr, size, k);
	return 0;
}