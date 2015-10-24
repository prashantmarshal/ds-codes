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
	node* start = head;
	while(start){
		cout<<start->data<<" ";
		start = start->next;
	}
	cout<<endl;
}

node* mergetwosortedlinkedlists(node **head1, node **head2){
	node *start1 = *head1, *start2 = *head2;
	node *result = NULL;
	node *result2 = result;

	if(start1 == NULL)
		result = start2;
	else if(start2 == NULL)
		result = start1;

	if(start1->data > start2->data){
		result = start2;
		start2 = start2->next;
	}else if(start1->data < start2->data){
		result = start1;
		start1 = start1->next;
	}

	result2 = result;

	while(start1 != NULL && start2 != NULL){
		if(start1->data > start2->data){
			result->next = start2;
			result = result->next;
			start2 = start2->next;
		}else if(start1->data < start2->data){
			result->next = start1;
			result = result->next;
			start1 = start1->next;
		}else{
			result->next = start1;
			result = result->next;
			start1 = start1->next;
		}
	}

	while(start1 != NULL){
		result->next = start1;
		result = result->next;
		start1 = start1->next;
	}

	while(start2 != NULL){
		result->next = start2;
		result = result->next;
		start2 = start2->next;
	}
	
	return result2;
}

node* mergetwosortedlinkedlistsrecursive(node *head1, node *head2){

	node *result = NULL;
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;

	if(head1->data < head2->data){
		result = head1;
		result->next = mergetwosortedlinkedlistsrecursive(head1->next, head2);
	}
	else{
		result = head2;
		result->next = mergetwosortedlinkedlistsrecursive(head1, head2->next);
	}

	return result;
}

int main(){
	linkedlist l1, l2;
	for(int i = 1; i < 15; i=i+2)
		l1.addNode(i);
	for(int i = 0; i < 10; i=i+2)
		l2.addNode(i);
	l1.display();
	l2.display();
	node *result = mergetwosortedlinkedlistsrecursive(l1.head, l2.head);
	display(result);
}