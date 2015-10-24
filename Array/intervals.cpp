#include <bits/stdc++.h>
using namespace std;

class t{
public:
	int a;
	int b;
};

bool compare(t a, t b){
	return a.b<b.b;
}
int main(){
	int n;
	cin>>n;
	int a,b;
	t arr[n];
	for(int i=0 ; i <n; ++i){
		cin>>a>>b;
		arr[i].a=a;
		arr[i].b = b;
	}

	sort(arr,arr+n,compare);

	int count=0;
	for(int i=0;i <n;++i){
		
	}
}