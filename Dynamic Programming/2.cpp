/*Min cost in a matrix*/

#include <iostream>
#include <climits>
using namespace std;

int min(int x, int y, int z){
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

int mincost(int cost[][3], int i, int j){
	if(i < 0 || j < 0)
		return INT_MAX;
	if(i == 0 && j == 0){
		return cost[i][j];
	}
	return cost[i][j] + min(mincost(cost, i-1, j-1), mincost(cost, i-1, j), mincost(cost, i, j-1));
}

int mincostdp(int cost[][3], int l, int b){
	
	int tc[l][b];
	tc[0][0] = cost[0][0];
	for(int i = 1; i <= l; ++i)
		tc[0][i] = cost[0][i] + tc[0][i-1];
	for(int i = 1; i <= b; ++i)
		tc[i][0] = cost[i][0] + tc[i-1][0];
	
	for(int i = 1; i <= l; ++i)
		for(int j = 1; j <= b; ++j)
			tc[i][j] = min(tc[i-1][j-1], tc[i-1][j], tc[i][j-1]) + cost[i][j];

	return tc[l][b];
}

int main(){
	int cost[][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
	cout<<mincostdp(cost, 2, 2);
}