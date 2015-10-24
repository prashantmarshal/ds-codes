/*Dynamic Programming | Set 28 (Minimum insertions to form a palindrome)*/

#include <bits/stdc++.h>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)
#define si(n) scanf("%d", &n)
#define pi(n) printf("%d", n)
#define sa(arr,a) for(int i=0; i<a; ++i) si(arr[i])

int mininsertionspalindrome(char s[]){
	int len = strlen(s);

	int t[len][len];


	for(int i = 0; i < len; ++i)
		for(int j = 0; j < len; ++j)
			t[i][j] = 0;

	for(int l = 2; l <= len; ++l){
		for(int i = 0; i < len-l+1; ++i){
			int j = i+l-1;
			if(s[i] != s[j])
				t[i][j] = min(t[i][j-1],t[i+1][j])+1;
			else
				t[i][j] = t[i+1][j-1];
		}
	}

	return t[0][len-1];	
}


int main(int argc, char const *argv[])
{
	char str[] = "geeks";
	cout<<mininsertionspalindrome(str);
	return 0;
}