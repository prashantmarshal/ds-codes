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

void alternatingsplitlinkedlist(linkedlist l1, linkedlist &l2, linkedlist &l3){
	node *start = l1.head;
	bool flag = 1;
	while(start != NULL){
		if(flag)
			l2.addNode(start->data);
		else
			l3.addNode(start->data);
		flag = !flag;
		start = start->next;
	}
}

int main(){
	linkedlist l1, l2, l3;
	for(int i = 1; i < 1; ++i)
		l1.addNode(i);
	l1.display();
	alternatingsplitlinkedlist(l1, l2, l3);
	l2.display();
	l3.display();
}