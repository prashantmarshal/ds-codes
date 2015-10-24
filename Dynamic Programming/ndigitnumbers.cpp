#include <bits/stdc++.h>
using namespace std;

#define for(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define pi(i) printf("%d", i)
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])

int recur(int n, int sum)
{
	if(n == 0) return sum == 0;
	int ans = 0;
	for(i,0,10){

		if(sum-i>=0) ans += recur(n-1,sum-i);	
	} 
	return ans;
	
}

int solve(int n, int sum)
{
	int ans=0;
	for(i,1,10) if(sum-i>=0) ans += recur(n-1, sum-i);
	return ans;

}

int main(int argc, char const *argv[])
{
	int n=2,sum=5;
	pi(solve(n,sum));
	return 0;
}