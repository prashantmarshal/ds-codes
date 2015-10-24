/*string array strings string to find in string array dictionary*/
#include <bits/stdc++.h>
using namespace std;

bool isthere(string arr[], string str, int size){
	for(int i=0; i<size; ++i){
		if(arr[i].compare(str) == 0){
			return true;
		}
	}
	return false;
}


bool solve(string arr[], int size, string str){
int len = str.length();
	bool t[len+1];
	memset(t,0,len+1);

	t[0]=true;
	for(int i=1 ;i<len+1; ++i){

		if(!t[i] && isthere(arr,str.substr(0,i),size))
			t[i] = 1;

		if(t[i]){
			for(int j=i+1; j<len+1; ++j){
				if(!t[j] && isthere(arr,str.substr(i,j-i),size))
					t[j] = 1;
				if(j == len && t[j])
					return true;
			}
		}
	}


	return false;
}


int main(int argc, char const *argv[])
{
	string arr[] = {"temp", "tempear", "earphone"};
	string str = "temptempear";
	int size = sizeof(arr)/sizeof(arr[0]);
	(solve(arr, size, str))?cout<<"Yes":cout<<"cant";	
	return 0;
}