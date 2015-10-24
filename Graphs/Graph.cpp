#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int V; // no. of nodes in the graph
	list<int> *adj;
public:
	void addedge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void DFS(int source, bool visited[]){
		list<int>::iterator i;
		visited[source] = true;
		cout<<source<<" ";
		for (i = adj[source].begin(); i != adj[source].end(); ++i){
			if(!visited[*i])
				DFS(*i, visited);
		}
	}

	void DFScall(int source = 0){
		bool visited[V];
		for(int i = 0; i < V; ++i)
			visited[i] = false;
		DFS(source, visited);
		// in case the graph is disconnected, we will have to call DFS from every vertex
		for(int i = 0; i < V; ++i){
			if(!visited[i])
				DFS(i, visited);
		}

	}

	void BFS(int source = 0){
		list<int> q;
		q.push_back(source); // if source is sent as an argument, we put source else the value of the first list adj[0]
		list<int>::iterator i;
		bool visited[V];
		for(int i = 0; i < V; ++i)
			visited[i] = false;
		visited[source] = true;
		while(!q.empty()){
			cout<<source<<" ";
			for(i = adj[source].begin(); i != adj[source].end(); ++i){
				if(!visited[*i]){
					q.push_back(*i);
					visited[*i] = true;
				}
			}
			q.pop_front();
			source = q.front();
		}
	}
	
	Graph(int V){
		this->V = V;
		adj = new list<int>[V];
	}


	/*bool isCyclic(int source, bool visited[]){ // for directed graph
		if(visited[source])
			return false;
		cout<<source<<endl;
		visited[source] = true;
		list<int>::iterator i; 
		for(i = adj[source].begin(); i != adj[source].end(); ++i){
			bool result = isCyclic(*i, visited);
			if(!result)
				return false;
		}

		return true;
	}

	bool isCyclicCall(int source){
		bool *visited = new bool[V];
		for(int i = 0; i < V; ++i)
			visited[i] = false;
		isCyclic(source, visited);
	}*/

	bool isCyclic(int source, bool visited[], int childof[], int parent){
		if(visited[source])
			return false;
		visited[source] = true;
		list<int>::iterator i; 

		for(i = adj[source].begin(); i != adj[source].end(); ++i){
			if(childof[source] == *i)
				continue;
			childof[*i] = source;
			bool result = isCyclic(*i, visited, childof, source);
			
			if(!result){
				return false;
			}
		}
		return true;
	}

	bool isCyclicCall(int source){
		bool *visited = new bool[V];
		for(int i = 0; i < V; ++i)
			visited[i] = false;
		int childof[V];
		for(int i = 0; i < V; ++i)
			childof[i] = -1;
		isCyclic(source, visited, childof, -2);
	}
};

int main(){

    Graph g1(5);
    g1.addedge(1, 0);
    g1.addedge(0, 2);
    g1.addedge(1, 4);
    g1.addedge(0, 3);
    g1.addedge(3, 4);
 
    Graph g2(3);
    g2.addedge(0, 1);
    g2.addedge(1, 2);

    if(g1.isCyclicCall(0)) cout<<"Not a cycle.\n";
    else cout<<"Cycle.\n";

	if(g2.isCyclicCall(0)) cout<<"Not a cycle.\n";
    else cout<<"Cycle.\n";

}