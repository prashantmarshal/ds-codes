#include <bits/stdc++.h>
using namespace std;

#define forr(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define pi(i) printf("%d", i)
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])


void solve(int arr[], int size)
{
	map<int, int> t;
	forr(i,0,size)
		t[arr[i]]++;
	
	for(map<int, int>::iterator it = t.begin(); it!=t.end(); ++it)
		if(it->second%2 == 0)
			cout<<it->first<<" ";

}	

int main(int argc, char const *argv[])
{
	int arr[100];
	int i = 0, size;
	while(cin>>arr[i++]);
	size = i-1;
	solve(arr, size);
	return 0;
}