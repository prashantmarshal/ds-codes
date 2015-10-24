#include <bits/stdc++.h>
using namespace std;



void solve(int n)
{
	int arr[100];
	int i = 0;
	while(n != 0){
		arr[i++] = n%2;
		n/=2;
	}

	i--;
	int sum = 0;
	
	for (int j = 0; j <= i; ++j)
		if(arr[j]==1){
			int temp = pow(5.0, j+1);
			sum+=temp;
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