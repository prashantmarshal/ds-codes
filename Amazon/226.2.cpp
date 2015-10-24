/*magic number 5 sums*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n){

	int arr[100];
	int i=0;
	memset(arr,0,100);
	while(n!=0){
		if(n%2 == 0)
			arr[i] = 0;
		else
			arr[i] = 1;
		n/=2; i++;
	}
	int sum = 0;
	for(int k = 0; k < i; ++k){
		if(arr[k] == 1)
		sum+=pow(5.0,k+1);
	}
	printf("%d\n", sum);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	solve(n);
	return 0;
}