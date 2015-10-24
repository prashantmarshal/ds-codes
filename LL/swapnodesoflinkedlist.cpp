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


void display(node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

node* swapnodesoflinkedlist(node *head){ // alternating swapping of nodes of linkedlist

	if(head == NULL)
		return NULL;
	node *temp = NULL, *first = head;
	if(head->next)
		temp = head->next->next;
	else
		return first;
	
	node *second = first->next;
	first->next->next = first;
	first->next = swapnodesoflinkedlist(temp);
	
	cout<<second->data<<endl;
	return second;

}

	
int main(){
	linkedlist l1;
	for(int i = 1; i < 7; ++i){
		l1.addNode(i);
	}
	display(swapnodesoflinkedlist(l1.head));
	
}