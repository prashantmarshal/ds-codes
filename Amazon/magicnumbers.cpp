#include <bits/stdc++.h>
using namespace std;


int solve(int t){
	bool arr[100];
	int j=0;
	while(t){
		if(t%2)
			arr[j++]=1;
		else
			arr[j++]=0;
		t/=2;
	}

	int sum = 0;
	for(int i = 0; i < j; ++i){
		if(arr[i])
			sum+=pow(5.0,i+1);
	}
	return sum;
}

int main()
{
	int t;
	cin>>t;
	cout<<solve(t);
	return 0;
}