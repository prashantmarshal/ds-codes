#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)
#define si(n) scanf("%d", &n)
#define pi(n) printf("%d", n)
#define sa(arr,a) for(int i=0; i<a; ++i) si(arr[i])

int main(int argc, char const *argv[])
{
	int n, k;
	si(n);si(k);
	int arr[n];
	sa(arr, n);
	int a,b;
	For(i,0,k){
		si(a);si(b);
		//find max
		int max = arr[a-1];
		For(i,a-1,b)
			if(arr[i]>max)
				max=arr[i];
		//get count
			int count=0;
			For(i,a-1,b)
				if(arr[i]==max)
					++count;
		pi(count);printf("\n");
	}
	return 0;
}