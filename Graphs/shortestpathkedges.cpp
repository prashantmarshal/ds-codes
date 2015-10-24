#include <iostream>
#include <climits>
using namespace std;
#define rows 4
#define columns 4
#define INF INT_MAX

int shortestpathkedges(int matrix[][columns], int u, int v, int k){
	if(k == 0 && u == v)
		return 0;
	if(k == 1 && matrix[u][v] != INF)
		return matrix[u][v];
	if(k <= 0)
		return INF;
	int res = INF;//, result;
	for (int i = 0; i < columns; ++i){

		if(matrix[u][i] != INF && u != i && v != i){
			int rec_res = shortestpathkedges(matrix, i, v, k-1);
			if(rec_res != INF)
				res = min(matrix[u][i] + rec_res, res);
		}
		
	}

	return res;
}

int shortestpathkedgesdp(int matrix[][columns], int u, int v, int k){
	int table[rows][columns][k+1];
	for(int l = 0; l <= k; l++){
		for(int i = 0; i < rows; ++i){
			for(int j = 0; j < columns; ++j){
				table[i][j][l]=INF;
				if(i == j && l == 0)
					table[i][j][l] = 0;
				if(l == 1 && matrix[i][j] != INF)
					table[i][j][l] = matrix[i][j];
				if(l > 1){
					for(int a = 0; a < columns; ++a){
						if(matrix[i][a] != INF && i != a && j != a && table[a][j][l-1] != INF){
							int rec_res = matrix[i][a] + table[a][j][l-1];
							table[i][j][l] = min(rec_res, table[i][j][l]);
						}
					}
				}
			}
		}
	}

	return table[u][v][k];
}


int main(){

	int matrix[rows][columns] = { {0, 10, 3, 2},
                        {INF, 0, INF, 7},
                        {INF, INF, 0, 6},
                        {INF, INF, INF, 0}
                      };
	cout<<shortestpathkedgesdp(matrix, 0, 3, 2);
}