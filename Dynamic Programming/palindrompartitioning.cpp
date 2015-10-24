/*palindrome min cuts*/

#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int mincutspalindrome(string str){
	int len = str.length();

	bool p[len][len];
	int c[len][len];
	memset(p,0,len*len*sizeof(bool));
	memset(c,0,len*len*sizeof(int));

	for(int i = 0; i < len; ++i)
		p[i][i] = 1;

	for(int l = 2; l <= len; ++l){
		for(int i = 0; i < len-l+1; ++i){
			int j = i+l-1;

			if(l == 2){
					p[i][j] = (str[i]==str[j]);
			else
				p[i][j] = (str[i]==str[j] && p[i+1][j-1]==true);

			if(p[i][j])
				c[i][j] = 0;
			else{
				int k = i;
				c[i][j] = 10000;
				for(;k<j;++k){
					c[i][j] = min(c[i][j], c[i][k]+1+c[k+1][j]);
				}
			}
		}
	}
	return c[0][len-1];
}

int main()
{
	char str[] = "ababbbabbababa";
	cout<<mincutspalindrome(str);
}