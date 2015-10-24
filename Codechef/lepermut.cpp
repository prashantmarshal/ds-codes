#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)


int main(){
	int T, N;
	cin>>T;

	while(T--){
		cin>>N;
		int *arr = new int[N];

		For(i,0,N)	
			cin>>arr[i];

		int li=0, gi=0;

		For(i,0,N-1){
			if(arr[i]>arr[i+1])
				++li;
		}

		For(i,0,N-1){
			For(j,i+1,N)
			if(arr[i]>arr[j])
				++gi;
		}

		if(li==gi)
			printf("YES\n");
		else
			printf("NO\n");
	}
}