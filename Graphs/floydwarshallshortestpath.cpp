/*floyd warshall algorithm for shortest paths*/
#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
#include <climits>
using namespace std;

#define INF 10000

int V = 4;

void floydwarshall(int graph[4][4]){

	int distance[V][V];

	for(int i = 0; i  <V; ++i)
		for (int k = 0; k < V; ++k)
			distance[i][k] = graph[i][k];


		for(int k = 0; k < V; ++k){
			for(int i = 0; i < V; ++i){
				for (int j = 0; j < V; ++j){
					if(distance[i][j] < distance[i][k]+distance[k][j]){
						distance[i][j] = distance[i][k]+distance[k][j];
					}	
				}
			}
		}

		for(int i = 0; i < V; ++i){
				for (int j = 0; j < V; ++j){
						if(distance[i][j] == INF)
							cout<<"INF"<<" ";
						else
							cout<<distance[i][j]<<" ";
				}
				cout<<endl;
			}


}

int main(){
	int graph[4][4] = { {0,   5,  INF, 10},
					{INF, 0,   3, INF},
					{INF, INF, 0,   1},
					{INF, INF, INF, 0}
					};
	
	floydwarshall(graph);					

}