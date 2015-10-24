#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <map>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)
#define si(n) scanf("%d", &n)
#define pi(n) printf("%d", n)
#define sa(arr,a) for(int i=0; i<a; ++i) si(arr[i])

int x[] = {1,-1,0,0};
int y[] = {0,0,1,-1};

int flag = 0;

vector< pair<int,int> >v;

void dodfs(int *arr[], int r, int c, int src_x, int src_y, bool *visited[], bool *seen[]){

	visited[src_x][src_y] = true;

	For(i,0,4){
			if(src_x+x[i] < 0 || src_x+x[i] >= r || src_y+y[i] < 0 || src_y+y[i] >= c)
				continue;
			if(arr[src_x+x[i]][src_y+y[i]] == 1 && !visited[src_x+x[i]][src_y+y[i]]){
				visited[src_x+x[i]][src_y+y[i]] = true;
				v.push_back(make_pair(src_x+x[i],src_y+y[i]));
				dodfs(arr, r, c, src_x+x[i], src_y+y[i], visited, seen);
			}
	}

}

int main(int argc, char const *argv[])
{
	int T;
	si(T);
	while(T--){
		flag = 0;
		int r,c;
		si(r);si(c);
		bool *visited[r];
		For(i,0,r){
			visited[i] = new bool[c];
			For(j,0,c)
			visited[i][j] = false;
		}
		int *arr[r];
		For(i,0,r)
			arr[i] = new int[c];
		char ch;
		int src_x, src_y;
		For(i,0,r)
		For(j,0,c){
			cin>>ch;
			switch(ch){
				case '.':
					arr[i][j]=1;
					break;
				case 'X':
					arr[i][j]=0;
					break;
				case 'M':
					src_x = i; src_y = j;
					arr[i][j]=5;
					break;
				case '*':
					arr[i][j]=2;
					break;
			}				
		}
		bool *seen[r];
		For(i,0,r){
			seen[i] = new bool[c];
			For(j,0,c)
			seen[i][j] = false;
		}
		
		dodfs(arr, r, c, src_x, src_y, visited, parent);
		int cmpr;
		si(cmpr);
		cout<<v.size();
		// cout<<flag<<" " <<cmpr<<endl;
		// if(cmpr != flag)
		// 	printf("Oops!\n");
		// else
		// 	printf("Impressed\n");

	}
	return 0;
}








	// cout<<src_x<<" "<<src_y<<endl;
	// for (int i = 0; i < r; ++i)
	// {
	// 	for (int j = 0; j < c; ++j)
	// 	{
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// return;


