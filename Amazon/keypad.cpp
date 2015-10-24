#include <bits/stdc++.h>
using namespace std;

void f(std::vector<string> v, int k, string str2, int vsize){

	if(k == vsize){
		cout<<str2<<" ";
		return;
	}
	int len = v[k].length();
	for(int i = 0; i < len; ++i){
		f(v,k+1,str2+v[k][i],vsize);
	}
}

int main(){
	int a = 4;
	int b = 11&(a-1);
	cout<<b<<endl;
	return 0;
	vector<string> v;
	char ch;

	std::map<int, string> t;
	t[2]="abc";
	t[3]="def";
	t[4]="ghi";
	t[5]="jkl";
	t[6]="mno";
	t[7]="pqrs";
	t[8]="tuv";
	t[9]="wxyz";

	while(cin>>ch){
		int n = ch-'0';
		v.push_back(t[n]);
	}

	int vsize = v.size();

	f(v,0,"",vsize);

}