#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define scanarr(arr,n) For(i,0,n) si(arr[i])
#define scanarrlong(arr,n) For(i,0,n) sl(arr[i])
#define ll long long int
#define getenter scanf("\n")


int main(int argc, char const *argv[])
{
	int t;
	ll x,y;
	cin>>t;
	while(t--){
        cin>>x>>y;
        int hsby = 0; // getting highest set bit
    	y = x^y;
    	while(y){
	    	hsby++;
	    	y /= 2;
	    }
    	x = x>>(hsby);
    	cout<<(ll)pow(2,hsby)*x<<endl;
    }
}