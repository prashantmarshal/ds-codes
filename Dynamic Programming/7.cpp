/*Dynamic Programming | Set 12 (Longest Palindromic Subsequence)*/

#include <iostream>
#include <string.h>
using namespace std;

int lps(char seq[], int start, int last){
	if(start == last)
		return 1;
	if(start > last)
		return 0;

	if(seq[start] == seq[last])
		return 2 + lps(seq, start+1, last-1);
	else
		return max(lps(seq, start+1, last), lps(seq, start, last-1));

}


int lpsdp(char seq[], int size){
	int L[size][size];
	memset(L, 0, sizeof(L));
	// setting up length = 1
	for(int i = 0; i < size; ++i)
		L[i][i] = 1;
	
	int maxlength = 1;

	for(int l = 2; l <= size; ++l){
		int offset = l-1;
		for(int i = 0; i < size - offset; ++i){
			if(seq[i] == seq[i+offset] && l == 2){
				L[i][i+offset] = 2;
				maxlength = 2;
			}
			else if(seq[i] == seq[i+offset]){
				L[i][i+offset] = 2 + L[i+1][i+offset-1];
				maxlength = l;
			}else{
				L[i][i+offset] = max(L[i][i+offset-1], L[i+1][i+offset]);
			}
		}
	}

	return L[0][size-1];

}

int main(){
    char seq[] = "GEEKSFORGEEKS";
    int size = strlen(seq);
    cout<<lps(seq, 0, size-1);cout<<endl;
    cout<<lpsdp(seq, size);
}