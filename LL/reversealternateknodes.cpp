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


node* reversealternateknodes(node *head, int k){

	if(head == NULL)
		return NULL;
	node *start = head;
	node *prev = NULL, *curr = NULL;
	int count = k;
	while(start != NULL && count){
		curr = start->next;
		start->next = prev;
		prev = start;
		start = curr;
		--count;
	}
	node *temp = head;
	head = prev;
	temp->next = curr;
	count = k;
	while(start!= NULL && count > 1){
		--count;
		start = start->next;
	}
	if(start)
		start->next = reversealternateknodes(start->next, k);
	return head;
}

node* reversealternateknodes(node *head, int k, bool flag){
	if(head == NULL)
		return NULL;
	node *start = head;
	node *curr = NULL, *prev = NULL;
	int count = k;
	if(flag){
		while(start != NULL && count){
			curr = start->next;
			start->next = prev;
			prev = start;
			start = curr;
			--count;
		}
		node *temp = head;
		head = prev;
		temp->next = reversealternateknodes(curr, k, !flag);
		return head;
	}else{
		int count = k;
		while(start != NULL && count > 1){
			start = start->next;
			--count;
		}
		start->next = reversealternateknodes(start->next, k, !flag);
		return head;
	}

}


void display(node *head){
	node* start = head;
	while(start){
		cout<<start->data<<" ";
		start = start->next;
	}
	cout<<endl;
}

int main(){
	linkedlist l1;
	for(int i = 1; i < 25; ++i)
		l1.addNode(i);
	l1.display();
	node *result = reversealternateknodes(l1.head, 3, true);
	display(result);
}