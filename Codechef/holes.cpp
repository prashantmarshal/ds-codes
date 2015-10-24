#include <iostream>
#include <cstdio>
#include <string.h>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)
#define scanint(n) scanf("%d", &n)
#define printint(n) printf("%d", n)

int main(int argc, char const *argv[])
{
	int T;
	scanint(T);
	scanf("\n");
	while(T--){

		char s[101];
		gets(s);
		int l = strlen(s), ans = 0;
		For(i,0,l){
			if(s[i]=='A' || s[i]=='D' || s[i]=='O' || s[i]=='P' || s[i]=='Q' || s[i]=='R')
				++ans;
			else if(s[i]=='B')
				ans += 2;
		}
		printint(ans);printf("\n");
	}
	return 0;
}