/*In a string detect the greatest window length with highest number of distinct characters.*/


#include <iostream>
#include <string.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

int longestlengthdistinctcharacters(string str){
	int l = str.length();
	int start = 0, last = 0;
	int chars[26];
	for(int i = 0; i < 26; ++i)
		chars[i] = -1;
	int maxlen = 0, currlen = 0, laststuck = 0;
	for(int i = 0; i < l; ++i){
		if(chars[str[i]-'a'] == -1){
			chars[str[i]-'a'] = i; // storing index
			currlen++;
		}else{
			if(chars[str[i]-'a'] > laststuck)
				laststuck = chars[str[i]-'a'];
			currlen = i - laststuck;
			chars[str[i]-'a'] = i;
		}
		maxlen = max(maxlen, currlen);
	}
	return maxlen;
}

int main(){
	string str = "aabcbcdbca";
	cout<<longestlengthdistinctcharacters(str);
}