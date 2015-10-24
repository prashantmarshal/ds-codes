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

	void removeDuplicate(node *head){
		if(head == NULL)
			return;
		node *start = head, *previous = start;
		int data = start->data;
		start = start->next;
		
		while(start != NULL){
			if(start->data == data){
				previous->next = start->next;
				delete(start);
				start = previous->next;
			}else{
				previous = start;
				start = start->next;
				if(start)
					data = start->data;
			}
		}

	}
};

int main(){
	linkedlist l1;
	for(int i = 0; i < 10; ++i){
		l1.addNode(i);
		l1.addNode(i);
	}
	l1.removeDuplicate(l1.head);
	l1.display();
}