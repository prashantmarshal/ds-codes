#include <iostream>
using namespace std;

int main(){
	int arr[][6] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };

    int R= 2,C=5;
    int top = 0, side=0;
    
    while(top <= C && side <= R){

    	for(int i = side; i <= C; ++i)
    		cout<<arr[top][i]<<" ";
    	top++;
    	if(top > R)
    		break;

    	for(int i = top; i <= R; ++i)
    		cout<<arr[i][C]<<" ";
		C--;
		if(side > C)
    		break;

    	for(int i = C; i >= side; --i)
    		cout<<arr[R][i]<<" ";
    	R--;

    	if(top > R)
    		break;

    	for(int i = R; i >= top; --i)
    		cout<<arr[i][side]<<" ";
    	side++;

    	if(side > C)
    		break;

    }

}