#include <bits/stdc++.h>
using namespace std;


int solve(long long int k){

	if(k == 1)
		return -1;
	if(k == 2)
		return -1;
	if(k == 3)
		return 1;
	long long int val = 1;
	while(val < k)
		val = val*2;
	
	if(k == val)
		return -1;
	--val;

	long long int diff = val-k;
	int value = solve(diff+1);
	return -1*value;
}

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	int test = 1;
	while(T--){
		long long int k;
		cin>>k;
		int val = solve(k);
		cout<<"Case #"<<test++<<": "<<((val==1)?1:0)<<endl;
	}
	return 0;
}