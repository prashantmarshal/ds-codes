#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	long long int m, n;
	cin>>m;
	int A[m];
	for (int i = 0; i < m; ++i)
		cin>>A[i];
	cin>>n;
	int B[n];
	for (int i = 0; i < n; ++i)
		cin>>B[i];

	sort(B, B+n);
	long long int ft[101];
	for (int i = 0; i < 101; ++i)
		ft[i] = 0;

	long long int base=B[0];
	for (int i = 0; i < n; ++i)
	{
		ft[B[i]-base]++;
	}

	for (int i = 0; i < m; ++i)
	{
		ft[A[i]-base]--;
	}
	int count = 0;
	for (int i = 0; i < 101; ++i)
	{
		if(ft[i] != 0)
			cout<<i+base<<" ";
	}
	cout<<endl;


    return 0;
}
