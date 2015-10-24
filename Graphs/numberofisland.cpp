#include <bits/stdc++.h>
using namespace std;
#define for(i,s,l) for(int i = s; i < l; ++i)

int x[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool issafe(int arr[][5], int i, int j, bool visited[][5])
{
	return (i >= 0 && i < 5 && j >= 0 && j < 5 && arr[i][j] && !visited[i][j]);
}

void dfs(int arr[][5], int i, int j, bool visited[][5])
{

	visited[i][j]=true;
	for(k,0,8){
		if(issafe(arr,i+x[k],j+y[k],visited))
			dfs(arr,i+x[k],j+y[k],visited);

	}
}

void solve(int arr[][5])
{
	bool visited[5][5];
	memset(visited,0,sizeof(visited));
	int count=0;
	for(i,0,5)
		for(j,0,5)
		{
			if(!visited[i][j] && arr[i][j]){
				dfs(arr, i, j, visited);
				++count;
			}
		}
	cout<<count<<endl;
}

int main(int argc, char const *argv[])
{
	int arr[][5] = {{1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1}};
        solve(arr);
	return 0;
}