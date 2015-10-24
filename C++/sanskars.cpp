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


void solve(){
	int N,K;
	si(N);si(K);

	vector<ll> v;
	ll intensity;

	ll sum = 0;

	For(i,0,N){
		sl(intensity);
		v.push_back(intensity);
		sum+=intensity;
	}

	/*
	2
5 3
1 2 4 5 6
5 3
1 2 4 5 7
	*/

	sort(v.begin(), v.end());
	int vsize = v.size();

	bool flag = true;
	if(sum%K != 0)
	{
		printf("no\n");
		return;
	}
	ll vali = sum/K;
	ll val;
	int i = 0, j = vsize-1;


	while(i<=j){
		val = vali;
		if(i == j && v[i]!=val){
			flag = false;
			break;
		}else if(i==j && v[i]==val){
			K--;
			break;
		}

		if(v[j]==val){
			K--;
			j--;
		}
		else{
			while(1){
				if(v[i]+v[j]==val){
					i++;j--;
					K--;
					break;
				}
				else if(v[i]+v[j] < val){
					val-=v[i];
					i++;
				}
				else if(v[i]+v[j] > val){
					flag = false;
					break;
				}
			}
		}
		if(flag==false){
			printf("no\n");
			break;
		}
	}

	if(flag && K==0)
		printf("yes\n");

}

int main(){
	int T;
	si(T);
	while(T--){
		solve();
	}

}