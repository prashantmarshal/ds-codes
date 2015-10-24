#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

bool isNumeric(char ch){
	if(isdigit(ch)){
		return true;
	}
	return false;
}


bool isOperator(char ch){
	switch(ch){
		case '+':
		case '-':
		case '*':
		return true;
	}
	return false;
}


void evaluatepostfix(char *arr){
	stack <int> mystack;
	for(int i = 0; arr[i]; ++i){
		if(isNumeric(arr[i])){
			mystack.push(arr[i]-'0');
		}else if(isOperator(arr[i])){
			int val1 = mystack.top(); mystack.pop();
			int val2 = mystack.top(); mystack.pop();
			switch(arr[i]){
				case '+':
					mystack.push(val2+val1);
					break;
				case '-':
					mystack.push(val2-val1);
					break;
				case '*':
					mystack.push(val2*val1);
					break;
			}
		}
	}
	cout<<mystack.top(); 
	mystack.pop();
	return;
}


int main(){
	char arr[] = "231*+9-";
	cout<<arr<<endl;
	evaluatepostfix(arr);
}