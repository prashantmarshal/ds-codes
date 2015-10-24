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
#define all(x) x.begin(),x.end()

int main(int argc, char const *argv[])
{
	string s = "prashant";
	s.replace(1,4,"okkkkkkk");
	cout<<s<<endl;
	return 0;
	

string inp;cin >> inp;
        if( next_permutation( all(inp) ) == false ) cout << "no answer" << endl;
        else cout << inp << endl;	
	return 0;
}
