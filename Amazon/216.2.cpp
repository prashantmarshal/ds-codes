/* largest number formed from numbers in array shuffle array according to largest number formed*/

#include <bits/stdc++.h>
using namespace std;

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
	string arr[] = {"2","985","9","3"};
	int size = sizeof(arr)/sizeof(arr[0]);
	vector<string> v;
	for (int i = 0; i < size; ++i)
		v.push_back(arr[i]);
	cout<<size<<endl;
	solve(v);
	return 0;
}