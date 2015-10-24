#include <bits/stdc++.h>
using namespace std;


list<int> arr[100001];
bool visited[100001];


void dodfs(int src, int n)
{
	visited[src]=true;
	int size = arr[src].size();
	int node;
	for(int i=0; i<size; ++i){
		node = arr[src].front();
		arr[src].pop_front();
		if(visited[node] == false && node != src)
			dodfs(node, n);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a,b;

	for(int i=0; i<n; ++i){
		cin>>a>>b;
		arr[a-1].push_back(b-1);
		arr[b-1].push_back(a-1);
	}
	int count=0;
	memset(visited,0,sizeof(visited));
	for(int i=0; i<n; ++i){
		if(!visited[i]){
			dodfs(i,n);
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}