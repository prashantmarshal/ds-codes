/*important*/
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <string.h>
using namespace std;

/*
int findlength(char *str){
	int l = strlen(str);
	int table[l][l];

	for(int i = 0; i < l; ++i)
		for (int j = 0; j < l; ++j)
			table[i][j] = 0;
		
	for(int i = 0; i < l; ++i)
		table[i][i] = str[i]-'0';

	int maxlen = INT_MIN;
	
	for(int length = 2; length <= l; ++length){
		for(int i = 0; i < l - length + 1; ++i){

			table[i][i+length-1] = table[i][i+length-2] + (str[i+length-1]-'0');
			int mid = (i+i+length)/2-1;

			if(table[i][mid] == table[mid+1][i+length-1] && maxlen < length)
				maxlen = length;
			
		}
	}

	// for(int i = 0; i < l; ++i){
	// 	for (int j = 0; j < l; ++j)
	// 		cout<<table[i][j]<<"         ";
	// 	cout<<endl;
	// }
	return maxlen;
}*/


int findlength(char *str){
	int l = strlen(str);
	int sum[l];
	sum[0] = 0;
	for(int i = 0; i < l; ++i)
		sum[i] = sum[i-1] + str[i]-'0';
	
	int maxlen = INT_MIN;
	for(int length = 2; length <= l; ++length)
		for(int i = 0; i < l-length+2; ++i)
			if(i == 0)
				if(sum[i+length/2-1] == sum[i+length-1]-sum[i+length/2-1])
					maxlen = max(maxlen, length);
			else
				if(sum[i+length/2-1]-sum[i-1] == sum[i+length-1]-sum[i+length/2-1])
					maxlen = max(maxlen, length);

	return maxlen;
}

int main(){
	char str[] = "123123";
	printf("Length of the substring is %d", findlength(str));
    return 0;
}