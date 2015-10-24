#include <bits/stdc++.h>
using namespace std;

struct jobs{
	// public:
	int s;
	int f;
	int val;
};

bool compare(jobs a, jobs b){
	return a.f < b.f;
}

int latest(jobs arr[], int i){
	for(int ind=i-1; ind>=0; --ind){
		if(arr[ind].f <= arr[i].s)
			return ind;
	}
	return -1;
}
int profit(jobs arr[], int n)
{
	sort(arr,arr+n,compare);
	int dp[n];
	dp[0] = arr[0].val;
	for(int i = 1; i < n; ++i){
		int l = latest(arr,i);
		if(l!=-1)
			dp[i] = max(dp[i-1], arr[i].val+dp[l]);
		else
			dp[i] = max(dp[i-1], arr[i].val);
	}

	int result = dp[n-1];
	delete[] dp;
	return result;
}

int main()
{
	jobs arr[4] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	cout<<profit(arr,4);
}