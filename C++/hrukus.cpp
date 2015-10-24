#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%lld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%lld", i);
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define scanarr(arr,n) For(i,0,n) si(arr[i])
#define scanarrlong(arr,n) For(i,0,n) sl(arr[i])
#define ll long long int
#define getenter scanf("\n")

int main(){
    int t;
    cin>>t;
    getenter;
    int count = 0;
    while(t--){
        string s;
        getline(cin,s);
        int l = s.length();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(s.find("hackerrank") != -1)
        	count++;
    }
    cout<<count<<endl;

}