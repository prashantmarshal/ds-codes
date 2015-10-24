/*Longest Palindromic Substring | Set 1*/

#include <iostream>
#include <string.h>
using namespace std;


int lps(char seq[], int size){
	bool table[size][size];
	memset(table, 0, sizeof(table));
	int maxlength = 0;
	// setting up length = 1
	for(int i = 0; i < size; ++i)
		table[i][i] = 1;

	// setting up length = 2
	for (int i = 0; i < size-1; ++i){
		if(seq[i] == seq[i+1]){
			table[i][i+1] = true;
			maxlength = 2;
		}
	}

	// checking for lengths greater than 2
	for(int l = 3; l <= size; ++l){
		int offset = l-1;
		for(int i = 0; i < size - offset; ++i){
			if(seq[i] == seq[i+offset] && table[i+1][i+offset-1] == true){
				table[i][i+offset] = true;
				maxlength = l;
			}
			else
				table[i][i+offset] = false; 
		}
	}

	return maxlength;

}

int main(){
    char seq[] = "qwertyuioppoiuytrewqqwertyuioppommkiolloasdfghjkllkjhgfdsa";
    int size = strlen(seq);
    cout<<lps(seq, size);
}