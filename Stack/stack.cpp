#include <iostream>
#include <stdio.h>
using namespace std;

class stack{
public:
	int *container;
	int top;

	stack(){
		container = new int[10];
		top = 0;
	}

	void push(int num){
		if(top >= 9)
			printf("Stack full\n");
		else
			container[top++] = num;
	}

	void peek(){
		cout<<"peek "<<top<<endl;
		if(top < 0){
			cout<<"Stack empty";
			return;
		}
		cout<<container[top]<<"\n";
	}

	int pop(){
		if(top < 0){
			cout<<"Stack empty";
			return -1;
		}
		return container[top--];
	}

	void display(){
		for(int i = 0; i < top; ++i)
			cout<<container[i]<<endl;
		cout<<endl;
	}

};
int main(){
	stack myStack;
	myStack.push(2);
	myStack.push(5);
	myStack.push(4);
	myStack.push(6);
	myStack.peek();
	myStack.pop();
	
	myStack.display();
}