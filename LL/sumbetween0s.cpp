#include <iostream>
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
		}
		cout<<endl;
	}
};

node* sumbetweenzeroes(linkedlist l){
	node *headll = l.head;
	node *head = l.head;
	node *start = head;
	int sum = 0;
	while(start != NULL){
		while(start != NULL && start->data != 0){
			sum+=start->data;
			start = start->next;
		}

		head->data = sum;
		if(start == NULL){
			head->next = NULL;
		}else{
			start = start->next;
			head = head->next;
		}
		sum = 0;
	}
	return headll;

}

int main(){
	linkedlist l1;
	l1.addNode(1);
	l1.addNode(2);
	l1.addNode(3);
	l1.addNode(0);
	l1.addNode(4);
	l1.addNode(5);
	l1.addNode(0);
	l1.addNode(6);
	node *headll = sumbetweenzeroes(l1);
	l1.display();
}