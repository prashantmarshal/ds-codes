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

	void deletealternatenodeslinkedlists(){
		node *start = head;
		if(start == NULL)
			return;
		node *previous = NULL;
		bool flag = 1;
		while(start != NULL){
			if(flag){
				previous = start;
				start = start->next;
				flag = !flag;
			}else{
				previous->next = start->next;
				delete(start);
				start = previous->next;
				flag = !flag;
			}
		}
	}

	
};


int main(){
	linkedlist l1;
	for(int i = 1; i < 10; ++i)
		l1.addNode(i);
	l1.display();
	l1.deletealternatenodeslinkedlists();
	l1.display();
}