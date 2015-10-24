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

node* oddeven(node *head){
	node *e, *eh=NULL;
	node *o, *oh=NULL;

	node *start = head;

	while(start != NULL){
		if(start->data%2 == 0){
			if(eh == NULL){
				eh = start;
				e = eh; 
				start = start->next;
			}else{
				e->next = start;
				start = start->next;
				e = e->next;
			}
		}else if(start->data%2 == 1){
			if(oh == NULL){
				oh = start;
				o = oh;
				start = start->next;
			}else{
				o->next = start;
				start = start->next;
				o = o->next;
			}
		}
	}
	e->next = NULL;
	o->next = eh;

	return oh; 
}

void display2(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main(){
	linkedlist l1;
	for (int i = 1; i < 2; ++i)
	{
	l1.addNode(i);
		/* code */
	}
	display2(oddeven(l1.head));
	// l1.display();
}