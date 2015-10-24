/*Dynamic Programming | Set 4 (Longest Common Subsequence)*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int longestcommonsubsequence(char a[], char b[], int alen, int blen){
	if(alen == 0 || blen == 0)
		return 0;

	if(a[alen-1] == b[blen-1]){
		return 1 + longestcommonsubsequence(a, b, alen-1, blen - 1);
	}else{
		return max(longestcommonsubsequence(a, b, alen, blen-1), longestcommonsubsequence(a, b, alen-1, blen));
	}

}

int longestcommonsubsequencedp(char a[], char b[], int alen, int blen){
	
	
	int *L[alen+1];
	for(int i=0; i<alen+1; ++i)
		L[i] = new int[blen+1]; // keeps track of longestcommonsubsequence till a[i] and b[j]
	
	
	for(int i = 0; i <= alen; ++i){
		for(int k = 0; k <= blen; ++k){
			if(i == 0 || k == 0)
				L[i][k] = 0;
			else if(a[i-1] == b[k-1])
				L[i][k] = 1 + L[i-1][k-1];
			else
				L[i][k] = max(L[i][k-1], L[i-1][k]);
		}
	}

	return L[alen][blen];
}

int main(){
	char a[50000];// = "HARRY";
	char b[50000];
	gets(a);
	cout<<"ok";
	gets(b);
	int m = strlen(a);
	cout<<"ok";

	int n = strlen(b);
	cout<<"ok";

	// cout<<longestcommonsubsequence(a, b, m, n);cout<<endl;
	cout<<longestcommonsubsequencedp(a, b, m, n)<<endl;
}