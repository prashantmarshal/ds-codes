/*string in string array dynamic programming*/

#include <bits/stdc++.h>
using namespace std;


bool iscontains(string arr[], int size, string str){
	for(int i= 0; i < size; ++i)
		if(arr[i].compare(str)==0)
			return true;

	return false;
}

bool solve(string arr[], string str,int size){

	int l = str.length();
	int p[str.length()];
	memset(p,0,str.length()*sizeof(int));


	for(int i = 0; i < l; ++i){

		if(p[i] == false && iscontains(arr,size,str.substr(0,i+1)))
			p[i]=true;

		if(p[i]){
			for(int j = i+1; j < l; ++j){
				if(p[j]==false && iscontains(arr,size,str.substr(i+1,j-i)))
					p[j] = true;
				if(j == l-1 && p[j] == true)
					return true;
			}
		}
	}

	return false;
}

int main(int argc, char const *argv[])
{
	string arr[] = {"tom","kaunhardy","chutiya","hai","but","hai","kaun","hardyhardy"};
	int size = sizeof(arr)/sizeof(arr[0]);
	string str = "kaunhardyhaibuthaikaunhardyhardy";

	if(solve(arr,str,size)){
		cout<<"yes"<<endl;
	}else 
	cout<<"no"<<endl;
	return 0;
}