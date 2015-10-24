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

void intersectionoftwosortedlinkedlists(linkedlist l1, linkedlist l2, linkedlist &l3){
	node *start1 = l1.head;
	node *start2 = l2.head;
	
	while(start1 != NULL && start2 != NULL){
		cout<<start1->data<<" "<<start2->data<<endl;
		if(start1->data > start2->data)
			start2 = start2->next;
		else if(start1->data < start2->data)
			start1 = start1->next;
		else{
			l3.addNode(start1->data);
			start1 = start1->next; start2 = start2->next;
		}
	}		
}

int main(){
	linkedlist l1, l2;
	for(int i = 0; i < 10; ++i)
		l1.addNode(i);
	for(int i = 5; i < 15; ++i)
		l2.addNode(i);
	linkedlist l3;
	intersectionoftwosortedlinkedlists(l1, l2, l3);
	l1.display();
	l2.display();cout<<endl;
	l3.display();
}