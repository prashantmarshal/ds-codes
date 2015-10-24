#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%ld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%ld", i);
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])


void solve(){
	long int N; long int M;
	sl(N); si(M);
	long int *arr = new long int[M];
	scan(arr,M);
	sort(arr,arr+M);
	long links = M-1;
	long int i = 0, count = 0;
	while(links>0){
		if(arr[i] == 1){
			links-=2;
			++i;
		}else{
			links--;
			arr[i]--;
		}
		++count;
	}

	pl(count);printf("\n");

}

int main(int argc, char const *argv[])
{
	int T;
	si(T);
	while(T--)
		solve();
	return 0;
}