/*Find length of the longest consecutive path from a given starting character*/
/*incomplete*/

#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;
#define r 3
#define c 3

int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};

int getmaxlength(char arr[][c], char source, int x1, int y1){


	int res = 1;
	for(int i = 0; i < sizeof(x)/sizeof(x[0]); ++i){
		for(int k = 0; k < sizeof(y)/sizeof(y[0]); ++k){
			if((x1+x[i] >=0) && (y1+y[k] >= 0) && (x1+x[i] <= r-1) && (y1+y[k] <= c-1) && (arr[x1+x[i]][y1+y[k]]-source == 1)){
				res = max(res, 1+getmaxlength(arr, arr[x1+x[i]][y1+y[k]], x1+x[i], y1+y[k]));
				cout<<res<<endl;
			}
		}
	}
	return res;
}

int main(){
	char mat[r][c] = { {'a','c','d'},
                     { 'h','b','a'},
                     { 'i','g','f'}};
                     cout<<getmaxlength(mat, 'i', 2, 0)<<endl;
                     // cout<<getmaxlength(mat, 'a', 2, 2);
}