#include <iostream>
using namespace std;

class node {
public:
	int data;
	node *next;
	node *previous;
};

class doublylinkedlist{
public:
	node *head, *start;
	doublylinkedlist(){
		head = NULL;
		start = head;
	}

	void addNode(int num){ // insert at the last
		if(head == NULL){
			head = new node();
			head->data = num;
			head->next = NULL; head->previous = NULL;
			start = head;
		}else{
			start->next = new node();
			start->next->data = num;
			start->next->next = NULL; start->next->previous = start; start = start->next;
		}
	}

	void insertAfter(int insertAfter, int num){
		node *start = head;
		if(start == NULL)
			return;
		while(start->data != insertAfter){
			start = start->next;
			if(start == NULL)
				return;
		}

		node *insertNew = new node();
		insertNew->data = num;
		insertNew->next = start->next;
		insertNew->previous = start;
		start->next = insertNew;
		if(insertNew->next != NULL)
			insertNew->next->previous = insertNew;

	}

	void insertBegin(int num){
		node *newNode = new node();
		newNode->data = num;
		newNode->next = head;
		newNode->previous = NULL;
		if(head != NULL) // in case the linkedlist was empty earlier
			head->previous = newNode;
		head = newNode;
	}

	void display(){
		node *start = head;
		while(start != NULL){
			cout<<start->data<<" ";
			start = start->next;
		}
		cout<<endl;
	}
	
	void deleteNode(int num){
		node *start = head;
		while(start->data != num)
			start = start->next;
		
		if(start->previous)
			start->previous->next = start->next;
		if(start->next)
			start->next->previous = start->previous;
		if(start->previous == NULL)
			head = start->next;
		delete(start);
	}

};

int main(){
	doublylinkedlist l1;
	l1.addNode(2);
	l1.addNode(3);
	l1.addNode(4);
	l1.addNode(5);
	l1.insertBegin(6);
	l1.display();
	l1.deleteNode(5);
	l1.display();
}