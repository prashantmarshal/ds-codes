/*check if anagram of one string is a substring of another subtring anagram*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])


bool check(int c[], int c2[]){
	for(int i = 0; i < 26; ++i)
		if(c[i]!=c2[i])
			return false;

		return true;
}

bool solve(string str1, string str2){

	int c[26],c2[26];
	int k = str2.length();

	memset(c,0,26*sizeof(int));
	memset(c2,0,26*sizeof(int));

	for(int i = 0; i < str2.length(); ++i){
		c2[str2[i]-'a']++;
	}

	for(int i = 0; i < str1.length(); ++i){
		c[str1[i]-'a']++;

		if(i>=k)
			c[str1[i-k]-'a']--;

		if(check(c,c2))
			return true;
	}

	return false;
}

int main(){
	string str1,str2;

	cin>>str1>>str2;

	if(solve(str1,str2))
		cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}