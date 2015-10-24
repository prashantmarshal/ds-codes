#include <iostream>
#include <stdio.h>
using namespace std;

int rows = 4;
int columns = 4;


int numberofpaths(int matrix[][5], int u, int v, int k){
	if(k == 0 && u == v)
		return 1;
	if(k == 1 && matrix[u][v])
		return 1;

	if(k <= 0)
		return 0;
	int count = 0;
	for(int i = 0; i < columns; ++i){
		if(matrix[u][i])
			count += numberofpaths(matrix, i, v, k-1);
	}

	return count;
}

int numberofpathsdp(int matrix[][4], int u, int v, int k){
	int table[4][4][k+1];

	for(int l = 0; l <= k; l++){
		for(int i = 0; i < rows; ++i){
			for(int j = 0; j < columns; ++j){
				
				table[i][j][l] = 0;
				
				if(i == j && l == 0)
					table[i][j][l] = 1;
				else if(matrix[i][j] && l == 1)
					table[i][j][l] = 1;
				
				if(l > 1){
					for(int a = 0; a < columns; a++){
						if(matrix[i][a]){
							table[i][j][l] += table[a][j][l-1];
						}
					}
				}
			}
		}
	}

	return table[u][v][k];
}

int main(){
	int matrix[][4]= { {0, 1, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                      };
	printf("Number of islands is: %d\n", numberofpathsdp(matrix, 0, 3, 2));
	return 0;
}