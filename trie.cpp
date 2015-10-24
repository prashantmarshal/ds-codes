#include <iostream>
#include <string.h>
using namespace std;
#define APLHA 26

class Tnode{
public:
	int value; // to check if any word ends here
	Tnode *child[APLHA];

	Tnode(){
		value = 0;
		for (int i = 0; i < APLHA; ++i)
			child[i] = NULL;
	}

};
class Trie{
public:
	Tnode *root;
	Trie(){
		root = new Tnode();
	}

	void insert(string s){
		int len = s.length();
		Tnode *temp = new Tnode();
		temp = root;
		for (int i = 0; i < len; ++i)
		{
			int val = s[i]-'a';
			if(temp->child[val]==NULL){
				temp->child[val] = new Tnode();
			}
			temp = temp->child[val];
		}
		temp->value = 1;
	}

	bool search(string s){
		int len = s.length();
		Tnode *temp = root;
		for (int i = 0; i < len; ++i)
		{
			int val = s[i]-'a';
			if(temp->child[val]){
				temp = temp->child[val];
			}else
			return 0;
		}

		return (temp->value && temp);
	}

};

int main(int argc, char const *argv[])
{
	string word[] = {"this","is","a","word","that","thatt","thiss","words"};
	Trie t;
	int len = sizeof(word)/sizeof(word[0]);
	for (int i = 0; i < len; ++i)
		t.insert(word[i]);
	for (int i = 0; i < len; ++i)
	{
		if(t.search(word[i]+"s"))
			cout<<"Word found : "<<word[i]<<endl;
		else 
			cout<<"Word not found : "<<word[i]<<endl;

	}
	return 0;
}