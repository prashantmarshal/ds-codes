/*Longest Even Length Substring such that Sum of First and Second Half is same*/

#include <bits/stdc++.h>
using namespace std;


void fdp(string str){
	int len = str.length();
	int str[len];
	s[0] = s[0]-'a';
	for(int i = 1; i < len; ++i){
		s[i] = s[0]+str[i]-'a';
	}

	for(int i = 0 ;i  < len; ++i){
		for(int j = i; j < len; ++j){
			if(j == i)
			{
				t[i][j] = 
			}
		}
	}

}

int main(int argc, char const *argv[])
{
	string s  = "1538023";
	int fdp(s);
	return 0;
}