#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

#define For(i,s,l) for(int i = s; i < l; ++i)
#define scanint(n) scanf("%d", &n)
#define printint(n) printf("%d", n)


void solve(){
	int nodes,edges;
	scanint(nodes);scanint(edges);

	map<pair<int,int>, bool> graph;
	graph.clear();
	int a,b;
	For(i,1,edges+1){
		scanint(a);scanint(b);
		graph[make_pair(min(a,b), max(a,b))] = true;
	}
	int source; scanint(source);

	queue<int>q;
	q.push(source);
	int done = 1;
	int dist[nodes+1];
	For(i,0,nodes+1)
		dist[i] = -1;
	dist[source] = 0;
	while(!q.empty()){

		if(done == nodes) // means that nodes number of nodes have been assigned distances hence no need to further continue
			break;
		int s = q.front();
		q.pop();

		For(i,1,nodes+1){
			int a = min(i, s);
			int b =  max(i, s);
			if((dist[i] != -1) || (i == s) || graph.count(make_pair(a,b)) > 0)
				continue;
			dist[i] = dist[s]+1;
			q.push(i);
			++done;
		}
	}

	For(i,1,nodes+1){
		if(dist[i] != 0){
			printint(dist[i]);printf(" ");
		}
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int T;
	scanint(T);
	while(T--)
		solve();
	return 0;
}