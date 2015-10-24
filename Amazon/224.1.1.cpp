#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(unsigned long long int i = s; i < l; ++i)

unsigned long long int ways(unsigned long long int left, unsigned long long int max){
	if(left == 0)
		return 1;
	if(left < 0)
		return 0;
	return ways(left-1, max)+ways(left-2, max)+ways(left-3, max);
}

unsigned long long int waysdp(unsigned long long int max){
	unsigned long long int dp[max+1];
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	For(i,3,max+1){
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	}

	return dp[max];
}

int main(int argc, char const *argv[])
{
	unsigned long long int max;
	cin>>max;
	cout<<ways(max, max)<<endl;
	cout<<waysdp(max)<<endl;
	return 0;
}