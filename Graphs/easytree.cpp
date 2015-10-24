#include <iostream>
#include <stdio.h>
using namespace std;

int ans = 0; 
int graphtreerecursion(int *arr[1000], int s, int nodes, bool *visited){

	visited[s] = true;

	int res = 1;
	for(int i = 0; i < nodes; ++i){
		if(arr[s][i] == 1 && !visited[i]){
			res += graphtreerecursion(arr, i, nodes, visited);
		}
	}
	if(res % 2 == 0)
		++ans;

	return res;

}

int main(){
	int nodes, M;
	cin>>nodes>>M;

	int *matrix[1000];
	for(int i = 0; i < nodes; i++)
		matrix[i] = new int[1000];
	for(int i = 0; i < nodes; ++i)
		for (int j = 0; j < nodes; ++j)
			matrix[i][j] = -1;
	
	bool visited[nodes];
	
	for(int i = 0; i < nodes; ++i)
		visited[i] = false;

	for(int i = 0; i < M; ++i){
		int u, v;
		cin>>u>>v;
		matrix[u-1][v-1] = 1;
		matrix[v-1][u-1] = 1;
	}

	graphtreerecursion(matrix, 0, nodes, visited);
	cout<<ans-1<<endl;
}