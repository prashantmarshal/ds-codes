/*employee ratings*/

#include <bits/stdc++.h>
using namespace std;


int solve(int ratings[], int size){
	int ranks[size];

	if(ratings[0] <= ratings[1])
		ranks[0] = 1;
	else ranks[0] = 2;
	if(ratings[size-1] > ratings[size-2])
		ranks[size-1]=2;
	else ranks[size-1]=1;

	for(int i = 1; i < size-1; ++i){
		if(ratings[i] > max(ratings[i-1], ratings[i+1]))
			ranks[i] = 3;
		else if(ratings[i] < min(ratings[i-1], ratings[i+1]))
			ranks[i] = 1;
		else if(ratings[i] == ratings[i-1] && ratings[i] == ratings[i+1])
			ranks[i] = 1;
		else if(ratings[i] == max(ratings[i-1], ratings[i+1]))
			ranks[i] = 2;
		else if(ratings[i] == min(ratings[i-1], ratings[i+1]))
			ranks[i] = 1;
	}

	for(int i = 0; i < size; ++i){
		cout<<ranks[i]<<" ";
	}
	cout<<endl;

	for(int i = 1; i < size; ++i){
		if(ratings[i] > ratings[i-1] && ranks[i] <= ranks[i-1])
			ranks[i] = 1+ranks[i-1];
		else if(ratings[i] == ratings[i-1] && ranks[i] < ranks[i-1])
			ranks[i] = ranks[i-1];
	}

	for(int i = size-2; i >=0; --i){
		if(ratings[i] > ratings[i+1] && ranks[i] <= ranks[i+1])
			ranks[i] = 1+ranks[i+1];
		else if(ratings[i] == ratings[i+1] && ranks[i] < ranks[i+1])
			ranks[i] = ranks[i+1];	
	}


	int sum = 0;
	for(int i = 0; i < size; ++i){
		cout<<ranks[i]<<" ";
		sum += ranks[i];
	}
	cout<<endl;

	return sum;
}

int main(){
	int ratings[] = {7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8};
	int size = sizeof(ratings)/sizeof(ratings[0]);

	cout<<solve(ratings, size);
}