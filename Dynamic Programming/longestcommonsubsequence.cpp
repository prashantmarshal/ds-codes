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
	int a, b;
	si(a);si(b);

	int arr1[a], arr2[b];
	sa(arr1, a);
	sa(arr2, b);

	int l[a+1][b+1];

	For(i,0,a+1){
		For(j,0,b+1){
			if(i==0 || j==0)
				l[i][j] = 0;
			else if(arr1[i-1] == arr2[j-1])
				l[i][j] = 1+l[i-1][j-1];
			else
				l[i][j] = max(l[i-1][j], l[i][j-1]);
		}
	}

	stack<int>s;
	int r = a, c = b;
	while(r > 0 && c > 0){
		
		if(arr1[r-1] == arr2[c-1]){
			s.push(arr1[r-1]);
			--r;--c;
		}else{
			if(l[r][c-1] > l[r-1][c])
				--c;
			else
				--r;
		}
	}

	int size = s.size();
	
	For(i,0,size){
		pi(s.top());printf(" ");
		s.pop();
	}
		
	return 0;
}