/*Find the minimum cost to reach destination using a train*/

#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;
#define INF INT_MAX

#define n 4

int mincost(int arr[][n], int start, int last){

	if(start == last || start+1 == last)
		return arr[start][last];
	int c = INT_MAX;
	for(int i = start; i < last; ++i){
		c = min(mincost(arr, start, i)+arr[i][last], c);
	}

	return c;
}

int mincostdp(int arr[][n]){
	int table[n];
	table[0] = 0;

	for(int i = 1; i < n; ++i){
		
		int res = 2000;

		for(int k = 1; k <= i; ++k){
			res = min(table[k-1] + arr[k-1][i], res);
		}
		table[i] = res;
	}

	return table[n-1];

}
int main(){
	int cost[n][n] = { {0, 15, 80, 90},
					{INF, 0, 40, 50},
					{INF, INF, 0, 70},
					{INF, INF, INF, 0}
				};
    cout << "The Minimum cost to reach station "
          << n << " is " << mincost(cost, 0, n-1);
    return 0;
}