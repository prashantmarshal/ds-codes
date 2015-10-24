#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)
#define si(n) scanf("%d", &n)
#define pi(n) printf("%d", n)
#define sa(arr,a) for(int i=0; i<a; ++i) si(arr[i])

int recur(stack<char> st, string s, int i, string cw, int cwl, int &cwc){
	// cout<<cw<<endl;
	// if(cwl = s.length() && cw == s)
	// 	++cwc; //incrementin correct word count
	if(i == s.length()){
		cout<<"This is fucking string prior "<<cw<<endl;

		while(!st.empty()){
			cw+=st.top();
			st.pop();
		}
		cout<<"This is fucking string "<<cw<<endl;
		if(cw == s){
			cout<<"OKOKOKOK";
			++cwc;
		}
		return 1;
	}

	if(st.empty())
		return 1;
	st.push(s[i]);
	int push=recur(st,s,i+1,cw,cwl,cwc);
	int pop;
	st.pop();
	if(!st.empty()){
		cout<<"tis is st.top() "<<st.top()<<endl;
		cw += st.top();
		st.pop();
		pop=recur(st,s,i,cw,cwl,cwc); //correctwordlength
	}
	
	return push+pop;
}

void solve(string s){
	stack<char>st;
	st.push(s[0]);
	string cw="";
	int cwc=0;
	int a=recur(st,s,1,cw,0,cwc);
	pi(cwc);printf(" ");pi(a);printf("\n");
}


int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	solve(s);
	return 0;
}