#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%ld", &i)
#define pi(i) printf("%d ", i)
#define pl(i) printf("%ld", i);
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])


void solve(int arr[][4]){
	int C=3,R=3;
	int row=0,col=0;

	while(true){
		For(i,col,C+1)
		pi(arr[row][i]);
		++row;
		cout<<endl;

		if(row > R || col > C)
			break;

		For(i,row,R+1)
		pi(arr[i][C]);
		C--;
cout<<endl;
		if(row > R|| col > C)
			break;

		for(int i=C; i>=col; --i){
			pi(arr[R][i]);
		}
		R--;
cout<<endl;
		if(row > R || col > C)
			break;

		for(int i=R; i>=row; --i){
			pi(arr[i][col]);
		}
		col++;
cout<<endl;
		if(row > R || col > C)
			break;
		printf("\n");

	}
}

int main(int argc, char const *argv[])
{
	int arr[][4]={
		{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
	};
	For(i,0,4)
	{
		For(j,0,4)
		cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	solve(arr);
	return 0;
}