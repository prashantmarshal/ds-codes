/*no of bsts*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(unsigned long long int i = s; i < l; ++i)
#define scanint(n) scanf("%lld", &n)
#define printint(n) printf("%lld", n);
#define LIM 1000000000
#define LIM7 100000007

int main(int argc, char const *argv[])
{
	unsigned long long int t;
	scanint(t);
	while(t--){
		unsigned long long int tt;
		// scanint(tt);
		cin>>tt;
		unsigned long long int F[tt+1];
		For(i,0,tt+1)
		F[i] = 0;
		F[0] = 1; F[1] = 1; F[2] = 2;
		For(i,3,tt+1){
			For(j,0,i){
				F[i] += (F[j]*F[i-1-j])%LIM;	
			}
		}
		cout<<F[tt]%LIM7<<endl;
		// printint(F[tt]);printf("\n");
	}
	return 0;
}