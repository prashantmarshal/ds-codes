/*string array strings string to find in string array dynamic programming*/
#include <bits/stdc++.h>
using namespace std;


bool isthere(string arr[], string str, int size){
	for(int i=0; i<size; ++i){
		if(arr[i].compare(str) == 0){
			cout<<"got"<<" "<<str<<endl;
			return true;
		}
	}
	return false;
}

bool check(string arr[], int size, string str, int start){
	if(str.size() == 0)
		return true;

	for(int i=1; i<=str.length(); ++i){
		if(isthere(arr, str.substr(0,i), size)){
			if(check(arr,size,str.substr(i,str.length()),0))
				return true;
		}
	}
	return false;
}

bool solve(string arr[], int size, string str)
{
	return check(arr,size,str,0);
}

int main(int argc, char const *argv[])
{
	string arr[] = {"temp", "tempear", "earphone"};
	string str = "tempearphone";
	int size = sizeof(arr)/sizeof(arr[0]);
	(solve(arr, size, str))?cout<<"Yes":cout<<"cant";	
	return 0;
}