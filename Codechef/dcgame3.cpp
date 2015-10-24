#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;


int main(){
	int n, games;
	cin>>n>>games;

	int *arr = new int[n];
	for(int i = 0; i < n; ++i)
		cin>>arr[i];
	char sign; int number; char player;

	for(int i = 0; i < games; ++i){
		cin>>sign>>number>>player;
		int count = 0;
		int cnt  = 0;
		for(int i = 0; i < n; ++i){
			int max = INT_MIN;
			for(int j = i; j < n; ++j){
				cnt++;
				if(arr[j] >= max)
					max = arr[j];
				
				if(sign == '=' && max == number)
					++count;
				else if(sign == '>' && max > number)
					++count;
				else if(sign == '<' && max < number)
					++count;
				
			}	
		}
		
		if(count%2 == 0){
			if(player == 'D')
				cout<<"C";
			else
				cout<<"D";
		}else{
			cout<<player;
		}

	}

}
