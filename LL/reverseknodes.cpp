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

node* reverseknodes(node *head, int k){ // recursive

	if(!head)
		return NULL;
	int count = k;
	node *first = head;
	node *previous = NULL, *curr = NULL;
	while(head != NULL && count){
		curr = head->next;
		head->next = previous;
		previous = head;
		head = curr;
		--count;
	}
	
	head = previous;
	first->next = reverseknodes(curr, k);
	return head;

}

node *reverseknodesrecursive(node *head, int k)
{
	if(!head)
		return NULL;
	int k2 = k;
	node *temp = NULL;
	node *head2 = head;
	node *previous = NULL;
	node *initial = head;
	while(k2-- && head){
		head->next = previous;
		previous = head;
		head = temp;
		if(temp)
			temp = temp->next;
	}
	
	initial->next = reverseknodesrecursive(head, k);
	head = previous;
	return head;
	
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
	node *result = reverseknodesrecursive(l1.head, 3);
	display(result);
}