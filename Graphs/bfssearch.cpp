/*shortest path from one node to every node*/

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;


void dobfs(int *arr[1000], int source, int nodes, int edges){

	int cost = 0;
	queue <int> q;

	bool visited[nodes]; bool assigned[nodes];
	for(int i = 0; i < nodes; i++)
		assigned[i] = false;
	q.push(source);
	assigned[source] = true;

	while(!q.empty()){
		int nodecount = q.size();
		cost += 6;
		while(nodecount--){
			int s = q.front();
			q.pop();

			for(int i = 0; i < nodes; ++i){
				if(arr[s][i] == 1 && !assigned[i]){
					arr[source][i] = cost;
					assigned[i] = true;
					q.push(i);
				}
			}
		}

	}
	
	for (int j = 0; j < nodes; ++j)
		if(j != source)
			cout<<arr[source][j]<<" ";


}

int main(){
	int T;
	cin>>T;

	while(T--){
		int nodes; 
		cin>>nodes; 
		int edges; 
		cin>>edges;
		
		int *matrix[1000];
		for(int i = 0; i < nodes; i++)
    		matrix[i] = new int[1000];

		for(int i = 0; i < nodes; ++i)
			for (int j = 0; j < nodes; ++j)
				matrix[i][j] = -1;

		for(int i = 0; i < edges; ++i){
			int u, v;
			cin>>u>>v;
			matrix[u-1][v-1] = 1;
			matrix[v-1][u-1] = 1;
		}

		int source;
		cin>>source;

		dobfs(matrix, source-1, nodes, edges);
			

	}
}