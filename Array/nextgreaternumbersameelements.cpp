/*Find next greater number with same set of digits*/

#include <bits/stdc++.h>
using namespace std;


int solve(char a[])
{
	int j = strlen(a);
	int mingw = j;
	while(j>=0){
		if(a[j] > mingw)
			mingw = j;
		if(a[j] > a[j-1]){
			j--;
			break;
		}

		j--;
	}
	int i;
	for(i=j+1;i<strlen(a);++i){
		if(a[i]>a[j] && a[i]<a[mingw])
			mingw = i;
	}

	swap(a[j],a[mingw]);
	
	sort(a+j+1,a+strlen(a));

}

int main(int argc, char const *argv[])
{
	char a[] = "3213213874321";
	solve(a);
	return 0;
}