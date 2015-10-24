#include <bits/stdc++.h>
using namespace std;



void solve(){
	int N,M;
	cin>>N>>M;
	long long int *arr = new long long int[N];

	for (int i = 0; i < N; ++i)
		cin>>arr[i];
	int a,b;
	for (int i = 0; i < M; ++i){
		cin>>a>>b;
		double d = b-a+1;
		double product = 1.0;
		for(int j = a; j <= b; ++j)
			product *= pow((double)arr[j], (double)1/d);
		printf("%0.9f\n", product);
	}
}

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	int test=1;
	while(T--){
		cout<<"Case #"<<test<<":"<<endl;
		solve();
		++test;
	}
	return 0;
}