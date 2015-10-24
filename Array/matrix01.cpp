#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void doit(int matrix[][5], int l){
	int R = 4;
	bool rows[4], cols[5];
	memset(rows,0,sizeof(rows));
	memset(cols,0,sizeof(cols));

	for(int i = 0;i < 4; ++i){
		for(int j = 0; j < 5; ++j){
			if(matrix[i][j] == 1){
				rows[i] = 1;
				cols[j] = 1;
			}
		}
	}

	for(int i = 0; i < 4; ++i){
		cout<<cols[i]<<" ";
	}
	cout<<endl;

	for(int i = 0; i < 4; ++i){
		if(rows[i] == 1){
			for(int j = 0; j < 5; ++j){
				matrix[i][j] = 1;
			}
		}
	}

	for(int i = 0; i < 5; ++i){
		if(cols[i] == 1){
			for(int j = 0; j < 4; ++j){
				matrix[j][i] = 1;
			}
		}
	}

	for(int i = 0; i < 4; ++i)
		{
			for(int j = 0; j < 5; ++j){
				cout<<matrix[i][j]<<" ";
			}cout<<endl;
		}

}

int main(int argc, char const *argv[])
{
	int matrix[][5] = { {0,0,0,1,0},
						{0,0,0,0,0},
						{0,0,0,1,0},
						{0,0,0,0,0}};
	doit(matrix,5);
	return 0;
}