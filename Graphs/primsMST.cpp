#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define V 5


int minkey(int *key, bool *mst){
	int min = INT_MAX;

	for(int i = 0; i < V; ++i)
		if(mst[i] == false && key[i] < min)
			min = i;
	mst[min] = true;
	return min;

}

int printmst(int parent[], int graph[V][V]){
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primsMST(int graph[][V]){
	int key[V], parent[V];
	bool mst[V];
	for(int i=0; i<V; ++i){
		key[i] = INT_MAX;
		parent[i] = -1;
		mst[i] = false;
	}

	int src = 0;
	key[src] = 0;
	parent[src] = -1;

	for(int i = 0; i < V; ++i){
		int u = minkey(key, mst); // gotten the vertex which is in queue and has the lowest key

		for(int j = 0; j < V; ++j){// for every adjacent vertex{
			if(graph[u][j] != 0 && key[j] > graph[u][j] && mst[j] == false){
				key[j] = graph[u][j];
				parent[j] = u;
			}
		}
	}

	printmst(parent, graph);


}

int main(){
	int graph[V][V] = {{0, 2, 0, 6, 0},
						{2, 0, 3, 8, 5},
						{0, 3, 0, 0, 7},
						{6, 8, 0, 0, 9},
						{0, 5, 7, 9, 0},
					};
	
	primsMST(graph);					
}