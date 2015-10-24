/*Arrange given numbers to form the biggest number sorting biggest number*/
#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%ld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%ld", i);
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])


bool compare(string a, string b){
	if(a.append(b) > b.append(a))
		return true;
	return false;
}
void solve(std::vector<string> v){
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); ++i)
	cout<<v[i];	
}

int main(int argc, char const *argv[])
{
	std::vector<string> v;
	v.push_back("2");
    v.push_back("985");
    v.push_back("9");
    v.push_back("3");
    solve(v);
	return 0;
}