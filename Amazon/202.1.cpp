/*important*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr[][6] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };

    int R = 2, C = 5;
    int top = 0, side = 0;
    int prev, curr;
    while(top <= R && side <= C){
        if(top+1 >= R || side+1 >= C)
            break;
    	prev = arr[top+1][side];
    	for(int i = side; i <= C; ++i){
    		curr = arr[top][i];
    		arr[top][i] = prev;
    		prev = curr;
    	}
    	top++;
    	if(top > R)
    		break;

    	for(int i = top; i <= R; ++i){
    		curr = arr[i][C];
    		arr[i][C] = prev;
    		prev = curr;	
    	}
    	C--;
    	if(side > C)
    		break;

    	for(int i = C; i >= side; --i){
    		curr = arr[R][i];
    		arr[R][i] = prev;
    		prev = curr;
    	}
    	R--;
    	if(top > R)
    		break;

    	for(int i = R; i >= top; --i){
    		curr = arr[i][side];
    		arr[i][side] = prev;
    		prev = curr;
    	}
    	side++;
    	if(side > C)
    		break;

    }

    for(int i = 0; i <= 2; ++i){
    	for(int j = 0; j <= 5; ++j){
    		cout<<arr[i][j]<<" ";
    	}
    	printf("\n");
    }
}