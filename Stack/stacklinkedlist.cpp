#include <iostream>
#include <stdio.h>
using namespace std;

class node{
public:
	int data;
	node *next;
	node(){
		next = NULL;
	}
};
class linkedlist{
public:
	node *head;
	node *start;
	linkedlist(){
		head= NULL;
		start = head;
	}

	void addNode(int num){
		if(head == NULL){
			head = new node();
			head->data = num;
			start = head;
		}else{
			start->next = new node();
			start->next->data = num;
			start = start->next;
		}
	}

	void display(){
		node *start = head;
		while(start != NULL){
			cout<<start->data<<" ";
			start = start->next;
		}cout<<endl;
	}

	
};
class stack{
public:
	linkedlist l;
	node *top;
	stack(){
		top = NULL;
	}
	void push(int num){
		l.addNode(num);
		if(!top)
			top = l.head;
	}
	void peek(){
		if(top)
			cout<<top->data<<endl;
	}
	void pop(){
		node **headref = &l.head;
		node *temp = *headref;
		*headref = (*headref)->next;
		top = *headref;
		delete(temp);
	}
	void display(){
		node *start = l.head;
		while(start != NULL){
			cout<<start->data<<" ";
			start = start->next;
		}cout<<endl;
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