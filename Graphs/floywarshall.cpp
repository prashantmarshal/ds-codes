#include <bits/stdc++.h>
using namespace std;
#define INF 10000
void printgraph(int arr[][4], int size){
	for (int i = 0; i < 4; ++i)
		{
			for (int k = 0; k < 4; ++k)
			{
				if(arr[i][k] == 10000)
					cout<<"INF"<<" \t\t";
				else
					cout<<arr[i][k]<<" \t\t";
			}
			cout<<endl;
		}
}

void floydwarshall(int arr[][4], int size){
	int dist[4][4];
	for(int l = 0; l < 4; ++l)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int k = 0; k < 4; ++k)
			{
				int d = dist[i][l]+dist[l][k];
				if(d < dist[i][k])
					dist[i][k] = d;
			}
		}
	}

	printgraph(arr,4);
}

int main(){
	int arr[][4] = {
		{0,5,8,9},
		{INF,0,3,INF},
		{INF,INF,0,1},
		{INF,INF,INF,0}
	};

	floydwarshall(arr,4);

}