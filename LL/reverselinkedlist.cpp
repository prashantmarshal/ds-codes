#include <iostream>
#include <stdio.h>
using namespace std;

class node{
public:
	int data;
	node *next;
};

class linkedlist{
public:
	node *head, *start;
	linkedlist(){
		head = NULL;
		start = head; // start pointer points to the last node in the list
	}
	void addNode(int num){ // node value to be added
		if(head == NULL){
			head = new node();
			head->data = num;
			head->next = NULL;
			start = head;
		}else{
			start->next = new node();
			start->next->data = num;
			start->next->next = NULL;
			start = start->next;
		}
	}
	void display(){
		node* start = head;
		while(start){
			cout<<start->data<<" ";
			start = start->next;
		}cout<<endl;
	}
};

node* reverseLinkedList(node **head){ // recursion

	if(*head == NULL)
		return NULL;
	node *first = *head;
	node *second = first->next;
	
	if(second == NULL)
		return first;

	second = reverseLinkedList(&second);
	first->next->next = first;
	first->next = NULL;

	return second;
	// *head = second;
}

void reverseLinkedListIterate(node **head){
	node *before = NULL;
	node *first = *head;
	node *second =  (*head)?(*head)->next:NULL;
	while(first != NULL){
		first->next = before;
		before = first;
		first = second;
		if(second)
			second = second->next;
	}
	*head = before;
}

void display(node *head){
	printf("\n");
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main(){
	
	linkedlist l1;
	for(int i = 1; i < 10; ++i)	l1.addNode(i);
	
	l1.display();	
	node *temp = reverseLinkedList(&l1.head);
	display(temp);
	// l1.display();
}