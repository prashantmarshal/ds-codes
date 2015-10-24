#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

bool isOperator(char ch){
	switch(ch){
		case '+':
		case '*':
		case '/':
		case '-':
		case '^':
			return true;
	}
	return false;
}
bool isVariable(char ch){
	switch(ch){
		case '+':
		case '*':
		case '/':
		case '-':
		case '^':
			return false;
	}
	return true;
}
int checkPrecedence(char ch){
	switch (ch){
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}


void infixToPostfix(char *exp){
	stack <char> mystack;
	char *arr = new char[100];
	int k = 0, count = 0;
	for(int j = 0; exp[j]; ++j)
		++count;

	for(int i = 0; i < count; ++i){

		if(exp[i] == '('){
			mystack.push(exp[i]);
		}

		else if(exp[i] == ')'){
			while(!mystack.empty() && mystack.top() != '('){
				arr[k++] = mystack.top();
				mystack.pop();
			}
			mystack.pop();
		}
		else if(isVariable(exp[i])){
			arr[k++] = exp[i];
		}
		

		else if(isOperator(exp[i])){
			if(mystack.size() != 0){				
				if(checkPrecedence(exp[i]) >= checkPrecedence(mystack.top())){
					mystack.push(exp[i]);
				}else{
					while(mystack.size() != 0 && checkPrecedence(exp[i]) <= checkPrecedence(mystack.top())){
						// keep removing from the stack until an operator of lesser precedence has been found
						arr[k++] = mystack.top();
						mystack.pop();
					}
					mystack.push(exp[i]);
				}
			}else
				mystack.push(exp[i]);
		}
	}

	printf("%s\n", arr);
	while(!mystack.empty()){
		if(mystack.top() != '(' || mystack.top() != ')')
			arr[k++] = mystack.top();
		mystack.pop();
	}
	printf("%s\n", arr);

	
}


int main(){

	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;

}


