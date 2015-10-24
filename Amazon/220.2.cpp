/*check if anagram of one string is a substring of another*/

#include <bits/stdc++.h>
using namespace std;
#define size(arr) sizeof(arr)/sizeof(arr[0])

bool check(int c1[], int c2[]){
	for (int i = 0; i < 26; ++i)
		if(c1[i]!=c2[i])
			return false;
	return true;
}

bool solve(string str1, string str2){
	
	int c1[26];
	memset(c1,0,26*sizeof(int));

	int l = str1.length();
	int k = str2.length();
	int c2[26];

	memset(c2,0,26*sizeof(int));

	for(int i=0; i<k; ++i)
		c1[str2[i]-'a']++;
	
	for(int i=0; i<l; ++i){
		
		c2[str1[i]-'a']++;
		
		if(i-k >= 0)
			c2[str1[i-k]-'a']--;
		
		if(check(c1,c2))
			return true;		
	}

	return false;


}

int main(){
	string str1;
	string str2;
	cin>>str1>>str2;
	if(solve(str1,str2))
		cout<<"yes\n";
	else
		cout<<"no\n";
}