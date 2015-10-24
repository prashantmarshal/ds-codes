#include <bits/stdc++.h>
using namespace std;

#define for(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define pi(i) printf("%d", i)
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])


int solve(string arr[], int low, int high, string str)
{
	if(low>high)
		return -1;
	int mid = (low+high)/2;
	if(arr[mid] == ""){
		int i = mid;
		while(i >= low && arr[i] == "") --i;
		if(i+1 == low)
			return solve(arr, mid+1, high, str);
		else{
			if(arr[i] > str)
				return solve(arr, low, i-1, str);
			else if(arr[i] < str)
				return solve(arr,mid+1, high, str);
			else if(arr[i] == str)
				return i;
		}
	}else if(arr[mid] > str)
		return solve(arr, low, mid-1, str);
	else if(arr[mid] < str)
		return solve(arr, mid+1, high, str);
	else if(arr[mid] == str)
		return mid;

}

int main(int argc, char const *argv[])
{
	string array[] = {"dog","","","","","","","","",""};
	int size = size(array);
	string str = "dog";
	cout<<solve(array, 0, size-1,str);
	return 0;
}