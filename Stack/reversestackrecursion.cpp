#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;


void fillstack(int top, stack <int> &mystack){
	if(mystack.size() == 0){
		mystack.push(top);
		return;
	}

	int temp = mystack.top();
	mystack.pop();
	fillstack(top, mystack);

	mystack.push(temp);

}


void reverseStack(stack <int> &mystack){
	if(mystack.size() == 0)
		return;
	int top = mystack.top();
	mystack.pop();
	reverseStack(mystack);
	fillstack(top, mystack);

}




int main(){
	stack <int> mystack;
	for(int i = 0; i < 5; ++i){
		mystack.push(i);
	}
	cout<<mystack.top();
	cout<<endl;
	reverseStack(mystack);
	cout<<mystack.top();

}