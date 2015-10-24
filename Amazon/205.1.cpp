/*first non repeating character*/

#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	char arr[] = "lkjlgmdlfkmk";
	int chars[26];
	memset(chars,0,26*sizeof(int));
	for(int i = 0; i < strlen(arr); ++i){
		chars[arr[i]-'a']++;
	}

	for(int i = 0; i < 26; ++i){
		if(chars[arr[i]-'a'] == 1){
			cout<<arr[i]<<endl;
			break;
		}
	}
	return 0;
}