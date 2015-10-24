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


bool solve(string arr[], int size, int sizearr, string str)
{
	if(size == 0)
		return true;

	bool w[size];
	memset(w,0,sizeof(w));

	for(int i = 0; i < size; ++i){
		if(w[i] == false && isthere(arr,str.substr(0,i+1),sizearr))
			w[i] = true;

		if(w[i]){

			for(int k=i+1; k<size; ++k){
				if(w[k]==false && isthere(arr,str.substr(i+1,k-i),sizearr))
					w[k] = true;
				if(k == size-1 && w[k] == true)
					return true;
			}
		}
	}

	return false;

}

int main(int argc, char const *argv[])
{
	string arr[] = {"hello", "how", "are", "you", "i", "am", "good"};
	string str = "areyouihowhowwellgood";
	int sizearr = sizeof(arr)/sizeof(arr[0]);
	int size = str.length();
	(solve(arr, size, sizearr, str))?cout<<"Yes":cout<<"cant";	
	return 0;
}