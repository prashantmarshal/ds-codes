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


bool isvowel(int a){
	if(a == 0)
		return true;
	else return false;
}

void printll(node *head){
	if(head==NULL)
		return;
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
}
void segregate(node *head){
	if(head == NULL)
		return;
	printll(head);
	node *ic= NULL, *c = NULL;
	node *iv = NULL, *v = NULL;

	node *start = head;

	while(start != NULL){
		
		if(isvowel(start->data)){
			if(v==NULL){
				v = new node();
				v = start;
				iv = v;
				start = start->next;
				v->next = NULL;
			}else {
				v->next = start;
				v = v->next;
				start = start->next;
				v->next = NULL;
			}
		}else{
			if(c==NULL){
				c = new node();
				c = start;
				ic = c;
				start = start->next;
				c->next = NULL;
			}else {
				c->next = start;
				c = c->next;
				start = start->next;
				c->next = NULL;
			}
		}
	}
	if(v)
		v->next = ic;
	cout<<endl;
	printll(iv);

}

int main(){
	linkedlist l1;
	l1.addNode(1);
	l1.addNode(0);
	l1.addNode(0);
	segregate(l1.head);
	// l1.display();
}