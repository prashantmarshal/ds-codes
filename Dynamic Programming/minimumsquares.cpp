/*Dynamic Programming — Minimum Numbers are Required Whose Square Sum is Equal To a Given Number*/

#include <bits/stdc++.h>
using namespace std;
#define intmax 10007

int solverecur(int t, int root){
	
	if(t == 0)
		return 0;
	if(t < 0)
		return intmax;
	if(root == 0 && t!=0)
		return intmax;
	
	if(root == 0)
		return 0;

	return min(1+solverecur(t-root*root, root),solverecur(t,root-1));
}

int solvedp(int x){
	int root=pow(float(x),0.5);
	int table[x+1][root+1];

	for(int i=0; i<x+1; ++i)
		table[i][0] = intmax;

	for(int i=0; i<root+1; ++i)
		table[0][i] = 0;

	for(int i = 1; i < x+1; ++i){
		for(int j = 1; j < root+1; ++j){
			if(i >= j*j)
				table[i][j] = min(1+table[i-j*j][j], table[i][j-1]);
			else 
				table[i][j] = table[i][j-1];
		}
	}

	return table[x][root];


}

int solve(int t){
	int root=pow(float(t),0.5);
	return solverecur(t, root);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	// cout<<solve(t)<<endl;
	cout<<solvedp(t);
	return 0;
}