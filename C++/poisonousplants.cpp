#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%lld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%lld", i);
#define scanarr(arr,n) For(i,0,n) si(arr[i])
#define scanarrlong(arr,n) For(i,0,n) sl(arr[i])
#define ll long long int
#define getenter scanf("\n")

int main(int argc, char const *argv[])
{
	int t,x,top;
	cin>>t;
	int arr[100001];	
	scanarr(arr,t);
	int e,count=0,i=0,j=0;
	bool flag = true, start = true;
	
	while(1){
		flag = false;start = true;
		i = 0, j = -1;
		while(i < t){
			e = arr[i];
			if(start){
				arr[++j] = e;
				start = false;
				top = e;
			}
			else{
				if(e > top) flag = true;
				else arr[++j] = e;
				top = e;
			}
			++i;
		}
		t = j+1;
		if(flag==false)
			break;
		++count;			
	}
	pi(count);printf("\n");
	return 0;
}