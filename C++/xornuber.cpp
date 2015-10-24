#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%lld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%lld", i);
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define ll long long int


int getans(int arr[32], int n){
	int i = 0;
	while(n){
		arr[i++] = (n%2);
		n /= 2;
	}
	For(j,0,i)
	if(arr[j] == 0)
		return -1;
	return pow(2.0,i-1)-1;
}

int main(){
	int T;
	si(T);
	int arr[32];
	while(T--){
		ll n;
		sl(n);

		if(n == 1){
			printf("2\n");
			continue;
		}
		memset(arr,0,32*sizeof(int));
		cout<<getans(arr,n);
		printf("\n");
	}
}