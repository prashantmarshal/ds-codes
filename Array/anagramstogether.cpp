/*print all anagrams together*/

#include <bits/stdc++.h>
using namespace std;

class pairs{
public:
	int index;
	string word;
};

bool compare(pairs one, pairs two){
	if(one.word.append(two.word) < two.word.append(one.word))
		return true;
	else return false;

}

int main(){
	string arr[] = {"cat","dog","god","act","tac","else"};
	int size = sizeof(arr)/sizeof(arr[0]);
	pairs ps[size];
	for(int i = 0; i < size; ++i){
		string str = arr[i];
		sort(str.begin(), str.end());
		ps[i].index = i;
		ps[i].word = str;
	}

	sort(ps,ps+size,compare);

	for(int i = 0; i < size; ++i){
		cout<<arr[ps[i].index]<<" ";
	}
}