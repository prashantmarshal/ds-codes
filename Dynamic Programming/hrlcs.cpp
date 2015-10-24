#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%lld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%lld", i);
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define sa(arr,n) For(i,0,n) si(arr[i])
#define salong(arr,n) For(i,0,n) sl(arr[i])
#define ull unsigned long long int
// #define max(a,b,c) (max(max(a,b),c))
#define max(a,b) max(a,b)
#define getenter scanf("\n")

int main(int argc, char const *argv[])
{
	int a,b;
	si(a);si(b);
	int arr[a];
	sa(arr,a);
	int arr2[b];
	sa(arr2,b);

	int L[a+1][b+1];
	memset(L,0,sizeof(L));

	For(i,1,a+1){
		For(j,1,b+1){
			if(arr[i-1] == arr2[j-1])
			{
				L[i][j] = 1+L[i-1][j-1];
			}else{
				L[i][j] = max(L[i-1][j],L[i][j-1]);
			}
		}
	}

	For(i,0,a+1)
	{
		For(j,0,b+1)
		cout<<L[i][j]<<" ";
		cout<<endl;
	}

	stack<int>s;
	while(a > 0 && b > 0){
		if(arr[a-1] == arr2[b-1]){
			s.push(arr[a-1]);
			a--;b--;

		}else if(L[a][b] == L[a-1][b])
			a--;
		else if(L[a][b] == L[a][b-1])
			b--;
	}

	while(!s.empty()){
		int top = s.top();
		pi(top);printf(" ");
		s.pop();
	}

	return 0;
}