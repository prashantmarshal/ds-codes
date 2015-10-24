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
		if(start == NULL)
			return;
		while(start){
			cout<<start->data<<" ";
			start = start->next;
		}cout<<endl;
	}
};

void deleteLinkedList(node *l){
	node *one = l;
	node *three = one;
	while(three != NULL){
		node *two = three;
		three = one->next;
		delete(two);
		one = NULL;
	}
}

int main(){
	linkedlist l1;
	for(int i = 1; i < 10; ++i)	
		l1.addNode(i);
	int beforeDelete = l1.head->data;
	l1.display();
	if((l1.head)->data == beforeDelete){
		printf("List not deleted.\n");
	}else{
		printf("List deleted.\n");
	}
	deleteLinkedList(l1.head);
	l1.display();
	if((l1.head)->data == beforeDelete){
		printf("List not deleted.\n");
	}else{
		printf("List deleted.\n");
	}
}