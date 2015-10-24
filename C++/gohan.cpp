#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%lld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%lld", i);
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define sa(arr,n) For(i,0,n) si(arr[i])
#define salong(arr,n) For(i,0,n) sl(arr[i])
#define ll long long int
#define max(a,b,c) (max(max(a,b),c))

int cnt = 0, ans = 0;
string rt;
map<string, int> t;

void func(string left, stack<char>s, string rt, int len, int pos){

	if(pos == len){
		while(!s.empty()){
			left = left+s.top();
			s.pop();
		}
		if(left.length() == len){
			if(t[left]==0){
				cnt++;
				t[left]=1;
			}
			if(left == rt)
				ans++;
		}
		return;
	}

	if(s.size() > 0){
		char top = s.top();
		s.pop();
		func(left+top,s,rt,len,pos);
		s.push(top);
		s.push(rt[pos]);
		func(left,s,rt,len,pos+1);
	}else{
		s.push(rt[pos]);
		func(left,s,rt,len,pos+1);
	}

}

int main(int argc, char const *argv[])
{
	cin>>rt;
	stack<char>s;
	func("",s,rt,rt.length(), 0);
	cout<<ans<<" " <<cnt<<endl;
	return 0;
}