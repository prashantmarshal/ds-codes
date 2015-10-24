/*Recursively print all sentences that can be formed from list of word lists*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

#define R 3
#define C 3

void printall(string arr[R][C], string sen, int i){

	if(i == R){
		cout<<sen<<endl;
		return;
	}

	for(int j = 0; j < C; ++j){
		if(arr[i][j] != "")
		printall(arr, (sen == "")?(sen+arr[i][j]):(sen+" "+arr[i][j]), i+1);
	}

}

int main(int argc, char const *argv[])
{
	string arr[R][C]  = {{"you", "we"},
        			{"have", "are"},
        			{"sleep", "eat", "drink"}};
 
   	printall(arr, "", 0);
}