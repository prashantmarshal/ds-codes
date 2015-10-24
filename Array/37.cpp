/*search in row wise and column wise sorted matrix*/

#include <bits/stdc++.h>
using namespace std;


void search(int arr[][4], int k){
	int i = 0, j = 3;

	while(1){
		if(k > arr[i][j]){
			++i;
		}else if(k < arr[i][j]){
			--j;
		}else{
			cout<<i << " " <<j<<endl;
			return;
		}

		if(i >= 0 && i < 4 && j >= 0 && j < 4)
			continue;
		else{
			printf("cant\n");
			break;
			return;
		}
	}
}

int main(int argc, char const *argv[])
{
	int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
	search(mat, 29);
	return 0;
}