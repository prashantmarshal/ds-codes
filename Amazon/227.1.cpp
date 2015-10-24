/*number of anagrams of a word in array*/

#include <bits/stdc++.h>
using namespace std;

void solve(string arr[], int t){
	int table[t][26];
	for(int i=0;i<t;++i)
		for(int k=0;k<26;++k)
			table[i][k]=0;

	for(int i = 0; i < t; ++i){
		string word = arr[i];
		for(int j = 0; j < word.length(); ++j){
			table[i][word[j]-'a']++;
		}
	}

	for(int i = 0; i < t; ++i){
		for(int j = 0; j < 26; ++j)
			cout<<table[i][j]<<" ";
		cout<<endl;
	}

	int cmap[t];
	memset(cmap,0,t*sizeof(int));

	for(int i = 0; i < t; ++i){
		for(int j=0;j<t; ++j){
			bool flag=1;
			for(int k=0;k<26;++k){
				if(table[i][k]!=table[j][k]){
					flag=0;
					break;
				}
			}
			if(flag)
				cmap[i]++;
		}
	}

	for(int i=0; i<t; ++i){
		cout<<cmap[i]<<" ";
	}

}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	string arr[t];
	for(int i = 0; i < t; ++i){
		cin>>arr[i];
	}
	solve(arr,t);
	return 0;
}