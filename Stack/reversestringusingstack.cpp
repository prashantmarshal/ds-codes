#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

void reverse(char **string){
	stack <char> mystack;
	char *str = *string;
	for (int i = 0; str[i]; ++i){
		mystack.push(str[i]);
	}

	int stacksize = mystack.size();
	for(int j = 0; j < stacksize; ++j){
		mystack.pop();
	}


	for(int i = 0; i < stacksize; ++i){
		cout<<mystack.top();
		(*string)[i] = mystack.top();
		mystack.pop();
	}
	cout<<*string<<endl;
}

int main(){
	
	char str[] = "prashant";
	char *string = str;
	reverse(&string);
	cout<<string<<endl;
}